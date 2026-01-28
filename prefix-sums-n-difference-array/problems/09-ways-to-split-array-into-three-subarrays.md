```cpp
class Solution {
public:
    const int MOD = 1e9+7;

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);

        for(int i = 1 ; i <= n ; ++i){
            pref[i] = pref[i-1] + nums[i-1];
        }

        long long count = 0;

        for(int i = 1 ; i <= n-2 ; ++i){
            int j = lower_bound(pref.begin()+i+1,
                                pref.begin()+n,
                                2LL*pref[i]) - pref.begin();

            long long limit = (pref[n] + pref[i]) / 2;

            int k = upper_bound(pref.begin()+i+1,
                                pref.begin()+n,
                                limit) - pref.begin() - 1;

            if(j <= k)
                count = (count + (k - j + 1)) % MOD;
        }

        return count;
    }
};
```