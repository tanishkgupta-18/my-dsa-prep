```cpp

class Solution {
public:
    int solve(int i, int target, vector<int>& nums,
              vector<vector<int>>& dp) {

        if (i == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = solve(i - 1, target, nums, dp);

        int take = 0;

        if (nums[i] <= target) {
            take = solve(i - 1, target - nums[i],
                         nums, dp);
        }

        return dp[i][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(),
                                  nums.end(), 0);

        if (abs(target) > totalSum)
            return 0;

        if ((totalSum + target) % 2 != 0)
            return 0;

        int required = (totalSum + target) / 2;

        vector<vector<int>> dp(
            nums.size(), vector<int>(required + 1, -1)
        );

        return solve(nums.size() - 1, required, nums, dp);
    }
};

```

```cpp

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = accumulate(nums.begin(),
                                  nums.end(), 0);

        if (abs(target) > totalSum)
            return 0;

        if ((totalSum + target) % 2 != 0)
            return 0;

        int required = (totalSum + target) / 2;

        vector<vector<int>> dp(
            n, vector<int>(required + 1, 0)
        );

        // Base case
        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;

            if (nums[0] <= required)
                dp[0][nums[0]] = 1;
        }

        // Transitions
        for (int i = 1; i < n; i++) {

            for (int j = 0; j <= required; j++) {

                int notTake = dp[i - 1][j];

                int take = 0;

                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][required];
    }
};
```

```cpp

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(),
                                  nums.end(), 0);

        if (abs(target) > totalSum)
            return 0;

        if ((totalSum + target) % 2 != 0)
            return 0;

        int required = (totalSum + target) / 2;

        vector<int> dp(required + 1, 0);

        dp[0] = 1;

        for (int num : nums) {
            for (int j = required; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[required];
    }
};
```