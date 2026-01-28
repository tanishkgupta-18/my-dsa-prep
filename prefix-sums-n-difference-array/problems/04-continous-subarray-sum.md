```cpp
/*NOTE: 
    prefixSum[i] % k == prefixSum[j] % k
    (prefixSum[i] - prefixSum[j]) % k == 0
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        // just find two consecutive zeros when k == 0
        if (k == 0) {
            for (int i = 1; i < n; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0)
                    return true;
            }
            return false;
        }

        unordered_map<int, int> mp;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem == 0 && i >= 1) return true;

            if (!mp.count(rem))
                mp[rem] = i;
            else if (i - mp[rem] > 1)
                return true;
        }

        return false;
    }
};
```