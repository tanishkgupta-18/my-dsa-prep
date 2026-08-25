```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            bool odd = mid&1;
            if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid == n-1 && nums[mid] != nums[mid-1]) return nums[mid];
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return nums[mid];
            if(odd){
                if(nums[mid] == nums[mid-1]) low = mid+1;
                else high = mid-1;
            }

            if(!odd){
                if(nums[mid] == nums[mid+1]) low = mid+1;
                else high = mid-1;
            }
        }

        return -1;
    }
};
```

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] == nums[mid^1]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }

        return nums[low];
    }
};
```