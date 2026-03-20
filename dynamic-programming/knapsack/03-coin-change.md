```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount+1, INF));

        for(int i = 0 ; i < n ; ++i) dp[i][0] = 0;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 1 ; j <= amount ; ++j){
                int pick = INF;
                if(coins[i] <= j){
                    int res = dp[i][j-coins[i]];
                    if(res != INF)
                        pick = 1 + res;
                }

                int skip = INF;
                if(i > 0){
                    skip = dp[i-1][j];
                }

                dp[i][j] = min(pick, skip);    
            }
        }

        return dp[n-1][amount] == INF? -1 : dp[n-1][amount];
    }
};
```