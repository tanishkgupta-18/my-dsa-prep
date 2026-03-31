## Memoization
```cpp
class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& memo){
        if(i > j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        int maxCoins = 0;
        for(int idx = i ; idx <= j ; ++idx){
            int coins = nums[i-1]*nums[idx]*nums[j+1] + helper(i , idx - 1 , nums , memo) + helper(idx + 1 , j , nums , memo);

            maxCoins = max(maxCoins,coins);
        }

        return memo[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> memo(n+2,vector<int>(n+2,-1));

        return helper(1,n,nums,memo);
    }
};
```

## Tabulation
```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i = n ; i >= 1 ; --i){
            for(int j = i ; j <= n ; ++j){
                int maxCoins = 0;
                for(int k = i ; k <= j ; ++k){
                    int coins = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxCoins = max(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};
```