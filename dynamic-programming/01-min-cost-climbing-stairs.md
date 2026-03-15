## Memoization
```cpp
class Solution {
public:

    int f(int i, vector<int>& cost, vector<int>& dp){

        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int one = cost[i] + f(i+1, cost, dp);
        int two = cost[i] + f(i+2, cost, dp);

        return dp[i] = min(one, two);
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

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};
```