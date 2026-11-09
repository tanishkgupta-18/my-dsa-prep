```cpp
class Solution {
public:
    int solve(int n,vector<int>& nums){
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1 ; i < n ; ++i){
            int pick = nums[i];
            if(i>1) pick = pick + dp[i-2];
            int npick = dp[i-1];
            dp[i] = max(pick , npick);
        }

        return dp[n-1];
    }
    int helper(int n ,vector<int>& nums){
        vector<int> a,b;
        if(n==1) return nums[0];
        for(int i = 0 ; i < n ; ++i){
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }

        return max(solve(n-1,a),solve(n-1,b));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return helper(n,nums);
    }
};
```