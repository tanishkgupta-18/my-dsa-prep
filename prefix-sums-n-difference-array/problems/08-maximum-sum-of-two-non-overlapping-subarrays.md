```cpp
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pref(n+1, 0);

        for(int i = 1 ; i <= n ; ++i) pref[i] = pref[i-1] + nums[i-1];

        int ans = 0;
        for(int i = 0 ; i <= n-firstLen ; ++i){
            int sum1 = pref[i+firstLen] - pref[i];
            
            for(int j = i+firstLen ; j <= n-secondLen ; ++j){
                int sum2 = pref[j+secondLen] - pref[j];
                ans = max(ans, sum1 + sum2);
            }
        }

        for(int i = 0; i <= n - secondLen; ++i){
            int sum1 = pref[i+secondLen] - pref[i];

            for(int j = i + secondLen; j <= n - firstLen; ++j){
                int sum2 = pref[j+firstLen] - pref[j];
                ans = max(ans, sum1 + sum2);
            }
        }

        return ans;
    }
};
```