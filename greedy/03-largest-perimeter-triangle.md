```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perimeter = 0;
        for(int i = 0 ; i < nums.size()-2 ; ++i){
            if(nums[i] + nums[i+1] > nums[i+2]){
                perimeter = nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return perimeter;
    }
};
```