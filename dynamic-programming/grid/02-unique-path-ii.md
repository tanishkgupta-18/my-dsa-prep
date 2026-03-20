```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        const int MOD = 2e9;

        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if (i == m - 1 && j == n - 1) continue;
                
                if (obstacleGrid[i][j]==1) {
                    dp[i][j] = 0;
                } else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
            }
        }

        return (int)dp[0][0];
    }
};
```