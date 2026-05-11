```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& arr, int n) {
    if(i == n - 1)
        return 0;

    if(i >= n || arr[i] == 0)
        return INT_MAX;

    int minSteps = INT_MAX;

    for(int jump = 1; jump <= arr[i]; jump++) {
        int next = i + jump;

        if(next < n) {
            int smallAns = solve(next, arr, n);

            if(smallAns != INT_MAX) {
                minSteps = min(minSteps, 1 + smallAns);
            }
        }
    }

    return minSteps;
}

int minimumJumps(vector<int> &arr, int n) {
    int ans = solve(0, arr, n);

    return (ans == INT_MAX) ? -1 : ans;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& arr, int n, vector<int>& dp) {

    // reached end
    if(i == n - 1)
        return 0;

    // cannot move further
    if(arr[i] == 0)
        return INT_MAX;

    // already computed
    if(dp[i] != -1)
        return dp[i];

    int minSteps = INT_MAX;

    for(int jump = 1; jump <= arr[i]; jump++) {

        int next = i + jump;

        if(next < n) {

            int smallAns = solve(next, arr, n, dp);

            // avoid overflow
            if(smallAns != INT_MAX) {
                minSteps = min(minSteps, 1 + smallAns);
            }
        }
    }

    return dp[i] = minSteps;
}

int minimumJumps(vector<int> &arr, int n) {

    vector<int> dp(n, -1);

    int ans = solve(0, arr, n, dp);

    return (ans == INT_MAX) ? -1 : ans;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> &arr, int n) {

    vector<int> dp(n, INT_MAX);

    // destination
    dp[n - 1] = 0;

    // move backwards
    for(int i = n - 2; i >= 0; i--) {

        // cannot move anywhere
        if(arr[i] == 0)
            continue;

        // try all jumps
        for(int jump = 1; jump <= arr[i]; jump++) {

            int next = i + jump;

            if(next < n && dp[next] != INT_MAX) {

                dp[i] = min(dp[i], 1 + dp[next]);
            }
        }
    }

    return (dp[0] == INT_MAX) ? -1 : dp[0];
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> &arr, int n) {

    // already at destination
    if(n <= 1)
        return 0;

    // cannot move anywhere
    if(arr[0] == 0)
        return -1;

    int jumps = 0;
    int farthest = 0;
    int currentEnd = 0;

    for(int i = 0; i < n - 1; i++) {

        // farthest reachable index
        farthest = max(farthest, i + arr[i]);

        // end of current jump range
        if(i == currentEnd) {

            jumps++;
            currentEnd = farthest;

            // cannot move further
            if(currentEnd <= i)
                return -1;
        }
    }

    return jumps;
}
```