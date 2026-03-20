## Memoization
```cpp
class Solution {
public:
    int f(int i, vector<int>& cost, vector<int>& dp){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int oneStep = f(i+1, cost, dp);
        int twoStep = f(i+2, cost, dp);

        return dp[i] = cost[i] + min(oneStep, twoStep); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};
```

## Tabulation
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);

        for(int i = n-1 ; i >= 0 ; --i){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};
```