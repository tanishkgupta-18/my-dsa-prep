```cpp
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0 ; j < n ; ++j)
            dp[n-1][j] = mat[n-1][j];
            
        for(int i = n-2 ; i >= 0 ; --i){
            for(int j = 0 ; j < n ; j++){ // no dependency on j is flexible
                if(j == 0) dp[i][j] = mat[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                else if(j == n-1) dp[i][j] = mat[i][j] + min(dp[i+1][j-1], dp[i+1][j]);
                else dp[i][j] = mat[i][j] + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
            }
        }
        
        int minSum = INT_MAX;
        for(int j = 0 ; j < n ; ++j)
            minSum = min(minSum, dp[0][j]);
            
        return minSum;
    }
};
```