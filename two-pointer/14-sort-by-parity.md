```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int k = 0, n = nums.size();

        for(int i = 0 ; i < n ; ++i){
            if(nums[i] % 2 == 0){
                swap(nums[i], nums[k]);
                k++;
            }
        }

        return nums;
    }
};
```