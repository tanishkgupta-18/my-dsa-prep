```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (amount == 0) return 1;
        if (n == 0) return 0; 
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount+1, 0));

        for(int i = 0 ; i < n ; ++i) dp[i][0] = 1;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 1 ; j <= amount ; ++j){
                unsigned int pick = 0;
                if(coins[i] <= j){
                    pick = dp[i][j-coins[i]];
                }

                unsigned int skip = 0;
                if(i > 0)
                    skip = dp[i-1][j];

                dp[i][j] = pick + skip;
            }
        }

        return dp[n-1][amount];
    }
};
```