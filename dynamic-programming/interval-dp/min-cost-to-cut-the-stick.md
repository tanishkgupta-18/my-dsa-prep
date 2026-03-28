```cpp
class Solution {
  public:
    int solve(int i, int j, vector<int>& cuts){
        if(i > j) return 0;
        
        int minCost = 1e9;
        for(int k = i ; k <= j ; ++k){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts) + solve(k+1, j, cuts);
            minCost = min(minCost, cost);
        }
        
        return minCost;
    }
    int minCutCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        return solve(1, N, cuts);
    }
};
```

## Tabulation
```cpp
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int N = cuts.size();

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        // dp[i][j] = min cost to cut from i to j
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));

        // i goes backward
        for(int i = N; i >= 1; --i){
            // j goes forward
            for(int j = i; j <= N; ++j){

                int minCost = 1e9;

                for(int k = i; k <= j; ++k){
                    int cost = cuts[j+1] - cuts[i-1] 
                             + dp[i][k-1] 
                             + dp[k+1][j];

                    minCost = min(minCost, cost);
                }

                dp[i][j] = minCost;
            }
        }

        return dp[1][N];
    }
};
```