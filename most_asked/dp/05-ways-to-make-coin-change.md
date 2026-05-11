```cpp
#include <vector>
long solve(int i, int value, int *denominations, vector<vector<long>>& dp){
    if(i < 0){
        return 0;
    }

    if(value == 0){
        return 1;
    }
    
    if(dp[i][value] != -1) return dp[i][value];

    long pick = 0;
    if(value >= denominations[i]){
        pick = solve(i, value-denominations[i], denominations, dp);
    }

    long skip = solve(i-1, value, denominations, dp);

    return dp[i][value] = pick + skip;
}
long countWaysToMakeChange(int *denominations, int n, int value){
    vector<vector<long>> dp(n, vector<long>(2001, -1));
    return solve(n-1, value, denominations, dp);
}
```

```cpp
#include <vector>
long countWaysToMakeChange(int *denominations, int n, int value){
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    
    for(int i = 0 ; i < n ; ++i) dp[i][0] = 1;

    for(int i = 0 ; i < n ; ++i){
        for(int j = 1; j <= value; j++){
            long pick = 0;
            if(j >= denominations[i]){
                pick = dp[i][j - denominations[i]];
            }

            long skip = 0;
            if(i > 0)
                skip = dp[i-1][j];

            dp[i][j] = pick + skip;
        }
    }

    return dp[n-1][value];
}
```