```cpp
class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size(), low = 0, high = n-1, ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int n = nums.size(), low = 0, high = n-1, ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lowerBound(nums, target);

        if(left == nums.size()) return {-1, -1};
        if(left != nums.size() && nums[left] != target) return {-1, -1};
        
        int right = upperBound(nums, target);

        return {left, right-1};
    }
};
```