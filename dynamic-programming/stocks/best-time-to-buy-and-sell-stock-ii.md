```cpp
class Solution {
public:
    int helper(vector<int>& prices,int idx,bool buy,vector<vector<int>>& memo){
        int n = prices.size();
        if(idx >= n) return 0;
        if(memo[idx][buy]!=-1) return memo[idx][buy];
        int maxProfit = 0;
        if(buy){
            int take = -prices[idx] + helper(prices,idx + 1,false,memo);
            int notTake = 0 + helper(prices,idx + 1,true,memo);
            maxProfit = max(take,notTake);
        }else{
            int take = prices[idx] + helper(prices,idx + 1,true,memo);
            int notTake = 0 + helper(prices,idx + 1,false,memo);
            maxProfit = max(take,notTake);
        }

        return memo[idx][buy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return helper(prices,0,true,memo);
    }
};
```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int day = n - 1 ; day >= 0 ; --day){
            for(int buy = 0 ; buy <= 1 ; ++buy){
                if(buy){
                    dp[day][buy] = max(-prices[day] + dp[day + 1][0],dp[day + 1][1]);
                }else{
                    dp[day][buy] = max(prices[day] + dp[day + 1][1],dp[day + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};
```

```cpp
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int total_profit = 0;
        
        // Start from index 1 because we compare with the previous day (i - 1)
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                total_profit += prices[i] - prices[i - 1];
            }
        }
        
        return total_profit;
    }
};
```