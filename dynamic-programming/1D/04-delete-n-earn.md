```cpp
class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>& dp) {
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = points[i] + solve(i - 2, points, dp);
        int notPick = solve(i - 1, points, dp);

        return dp[i] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return solve(maxi, points, dp);
    }
};
```

> Tabulation
```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, 0);

        dp[0] = points[0];

        if (maxi >= 1) {
            dp[1] = max(points[0], points[1]);
        }

        for (int i = 2; i <= maxi; i++) {
            int pick = points[i] + dp[i - 2];
            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[maxi];
    }
};
```