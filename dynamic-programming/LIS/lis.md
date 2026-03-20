```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // memo[curr_idx][next_idx]
        // next_idx is the index of the element we picked to the RIGHT of curr_idx
        // We use n as a special value for next_idx to mean "no element picked yet"
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        return solve(n - 1, n, nums, memo);
    }

private:
    int solve(int i, int next_idx, vector<int>& nums, vector<vector<int>>& memo) {
        // Base case: we've moved past the start of the array
        if (i < 0) {
            return 0;
        }

        // Check memoization table
        if (memo[i][next_idx] != -1) {
            return memo[i][next_idx];
        }

        // Option 1: Don't include nums[i] in the subsequence
        int notTake = solve(i - 1, next_idx, nums, memo);

        // Option 2: Include nums[i]
        int take = 0;
        // We can take nums[i] if:
        // 1. No element has been picked yet (next_idx == n)
        // 2. nums[i] is strictly less than the element picked to its right
        if (next_idx == nums.size() || nums[i] < nums[next_idx]) {
            take = 1 + solve(i - 1, i, nums, memo);
        }

        return memo[i][next_idx] = max(take, notTake);
    }
};
```

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // dp[i][next] → using first i elements (0 to i-1)

        for(int i = 1; i <= n; i++){
            for(int next = 0; next <= n; next++){

                // not take
                int notTake = dp[i-1][next];

                // take
                int take = 0;

                if(next == n || nums[i-1] < nums[next]){
                    take = 1 + dp[i-1][i-1];
                }

                dp[i][next] = max(take, notTake);
            }
        }

        return dp[n][n];
    }
};
```