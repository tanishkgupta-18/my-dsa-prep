```cpp
class Solution {
public:

    int solve(int day, int last, vector<vector<int>>& mat,
              vector<vector<int>>& dp) {

        // Base case
        if(day == 0) {

            int maxi = 0;

            for(int act = 0; act < 3; act++) {
                if(act != last) {
                    maxi = max(maxi, mat[0][act]);
                }
            }

            return maxi;
        }

        // Memoization
        if(dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for(int act = 0; act < 3; act++) {

            if(act != last) {

                int points = mat[day][act] +
                             solve(day - 1, act, mat, dp);

                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return solve(n - 1, 3, mat, dp);
    }
};
```

```cpp
class Solution {
public:

    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day 0

        dp[0][0] = max(mat[0][1], mat[0][2]);

        dp[0][1] = max(mat[0][0], mat[0][2]);

        dp[0][2] = max(mat[0][0], mat[0][1]);

        dp[0][3] = max({mat[0][0], mat[0][1], mat[0][2]});

        // Fill DP table

        for(int day = 1; day < n; day++) {

            for(int last = 0; last < 4; last++) {

                dp[day][last] = 0;

                for(int act = 0; act < 3; act++) {

                    if(act != last) {

                        int points =
                            mat[day][act] + dp[day - 1][act];

                        dp[day][last] =
                            max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};
```