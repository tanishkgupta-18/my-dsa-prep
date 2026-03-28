## Memoization
```cpp
class Solution {
  public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int minCost = 1e9;
        for(int k = i ; k < j ; ++k){
            int cost = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
            minCost = min(minCost, cost);
        }
        
        return dp[i][j] = minCost;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(1, n-1, arr, dp);
    }
};
```

## Tabulation
```cpp
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n-1 ; i >= 1 ; --i){
            for(int j = i+1 ; j < n ; ++j){
                int minCost = 1e9;
                for(int k = i ; k < j ; ++k){
                    int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    minCost = min(minCost, cost);
                }
                
                dp[i][j] = minCost;
            }
        }
        
        return dp[1][n-1];
    }
};
```