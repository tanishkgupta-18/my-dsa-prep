```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pref(n+1, 0), suff(n+1, 0);
        
        for(int i = 1 ; i <= n ; ++i){
            pref[i] = pref[i-1] + nums[i-1];
            suff[i] = suff[i-1] + nums[n-i];
        }

        unordered_map<int, int> sufIndex;
        for(int i = 0 ; i <= n ; ++i){
            if(!sufIndex.count(suff[i])) sufIndex[suff[i]] = i;
        }

        int ops = INT_MAX;
        for(int i = 0 ; i < n ; ++i){
            int rem = x - pref[i];
            if(sufIndex.count(rem)){
                int j = sufIndex[rem];

                if(i + j <= n) ops = min(ops, i+j);
            }
        }

        return (ops == INT_MAX)? -1 : ops;
    }
};
```

## Optimised Solution

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int remaining = total - x;
        if(remaining < 0) return -1;

        int i = 0, sum = 0, maxLen = -1;
        for(int j = 0 ; j < n ; ++j){
            sum += nums[j];

            while(sum > remaining && i <= j){
                sum -= nums[i++];
            }

            if(sum == remaining) maxLen = max(maxLen, j-i+1);
        }

        return maxLen == -1 ? -1 : n-maxLen;
    }
};
```