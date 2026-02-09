```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0 ; i < N ; ++i){
            int complement = target - nums[i];
            if(mp.count(complement)){
                return {mp[complement],i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```