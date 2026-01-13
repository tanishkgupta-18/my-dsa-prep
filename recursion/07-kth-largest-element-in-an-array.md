```cpp
class Solution {
public:
    int partition(int l, int r, vector<int>& nums){
        int pivot = nums[r];

        int i = l;
        for(int j = l ; j < r ; ++j){
            if(nums[j] > pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[r]);

        return i;
    }

    int quickSelect(int l, int r, vector<int>& nums, int k){
        if(l <= r){
            int p = partition(l, r, nums);

            if(p == k) return nums[p];
            if(p > k) return quickSelect(l, p-1, nums, k);
            else return quickSelect(p+1, r, nums, k);
        }

        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        return quickSelect(0, n-1, nums, k-1);
    }
};
```