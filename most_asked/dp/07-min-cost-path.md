```cpp
#include <bits/stdc++.h>

int minCostPath(int** cost, int n, int m, int x, int y){
    vector<vector<int>> dp(x, vector<int>(y, INT_MAX));

    dp[0][0] = cost[0][0];

    for(int i = 0 ; i < x ; ++i){
        for(int j = 0 ; j < y ; ++j){
            if(i == 0 && j == 0) continue;

            int top = (i > 0 ? dp[i-1][j] : INT_MAX);
            int left = (j > 0 ? dp[i][j-1] : INT_MAX);
            int diagonal = (i > 0 && j > 0 ? dp[i-1][j-1] : INT_MAX);

            dp[i][j] = cost[i][j] + min({top, left, diagonal}); 
        }
    }

    return dp[x-1][y-1];
}
```