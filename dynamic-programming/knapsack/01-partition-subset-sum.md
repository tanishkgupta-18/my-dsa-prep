```cpp
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total&1) return false;
        
        int target = total/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        
        // base cases
        if(arr[0] <= target)
            dp[0][arr[0]] = true;
        
        for(int i = 0 ; i < n ; ++i)
            dp[i][0] = true;
            
        for(int i = 1 ; i < n ; ++i){ 
            for(int j = 1 ; j <= target ; ++j){
                bool pick = false;
                
                if(arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];
                
                bool skip = dp[i-1][j];
                
                dp[i][j] = pick || skip;
            }
        }
        
        return dp[n-1][target];
    }
};
```