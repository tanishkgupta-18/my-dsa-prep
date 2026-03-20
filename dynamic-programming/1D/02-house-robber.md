```cpp
class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& memo){
        if(i >= nums.size()) return 0;

        if(memo[i] != -1) return memo[i];

        int take = nums[i] + helper(i + 2, nums, memo);
        int skip = helper(i + 1, nums, memo);

        return memo[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(0, nums, memo);
    }
};
```

```cpp
class Solution {
  public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0);
        for(int i=n-1; i>=0; --i){
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }
        
        return dp[0];
    }
};
```