> store prev values
```cpp
int solve(int i, int next, int arr[], unordered_map<int, unordered_map<int, int>>& dp){
    if(i < 0) return 0;

    if(dp[i].count(next)) return dp[i][next];
    int pick = 0;
    if(next > arr[i]){
        pick = 1 + solve(i-1, arr[i], arr, dp);
    }

    int skip = solve(i-1, next, arr, dp);

    return dp[i][next] = max(pick, skip);
}

int longestIncreasingSubsequence(int arr[], int n){
    unordered_map<int, unordered_map<int, int>> dp;
    return solve(n-1, 1e7, arr, dp);
}
```

> instead of values we store the prev indices and +1 because the prev can be -1 as well
```cpp
int solve(int i, int prev, vector<int>& arr, vector<vector<int>>& dp) {

    if(i == arr.size()) return 0;

    if(dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int take = 0;

    if(prev == -1 || arr[i] > arr[prev]) {
        take = 1 + solve(i + 1, i, arr, dp);
    }

    int notTake = solve(i + 1, prev, arr, dp);

    return dp[i][prev + 1] = max(take, notTake);
}
```

> tabulation approach
```cpp
int longestIncreasingSubsequence(vector<int>& arr) {

    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int i = n - 1; i >= 0; i--) {

        for(int prev = i - 1; prev >= -1; prev--) {

            int take = 0;

            if(prev == -1 || arr[i] > arr[prev]) {
                take = 1 + dp[i + 1][i + 1];
            }

            int notTake = dp[i + 1][prev + 1];

            dp[i][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}
```
> binary search approach MOST OPTIMAL SOLUTION
```cpp
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {

    vector<int> temp;

    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++) {

        // Extend LIS
        if(arr[i] > temp.back()) {

            temp.push_back(arr[i]);
        }
        else {

            // Find first element >= arr[i]
            int idx = lower_bound(temp.begin(),
                                  temp.end(),
                                  arr[i]) - temp.begin();

            temp[idx] = arr[i];
        }
    }

    return temp.size();
}
```
