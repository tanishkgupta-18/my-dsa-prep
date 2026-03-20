```cpp
class Solution {
public:
    int countPaths(int i, int j, int m, int n) {
        // Base Case: Reached the destination
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        // Base Case: Out of bounds
        if (i >= m || j >= n) {
            return 0;
        }
        
        // Recursive moves: Down + Right
        return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n) {
        return countPaths(0, 0, m, n);
    }
};
```
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        const int MOD = 2e9;

        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if (i == m - 1 && j == n - 1) continue; // to avoid overwrite of dp[m-1][n-1]
                
                dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
            }
        }

        return dp[0][0];
    }
};
```