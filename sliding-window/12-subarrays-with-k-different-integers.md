```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int, int> freq;
        int i = 0, res = 0;
        for(int j = 0 ; j < nums.size() ; ++j){
            freq[nums[j]]++;

            while(freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }

            res += (j-i+1);
        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
```