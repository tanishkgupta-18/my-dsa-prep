```cpp
class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] >= target) r = mid;
            else l = mid+1;
        }

        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);

        return lb;
    }
};
```