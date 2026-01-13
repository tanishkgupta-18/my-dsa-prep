```cpp
class Solution {
public:
    int findSubArray(int l, int r, vector<int>& nums){
        if(l == r) return nums[l];

        int mid = l + (r-l)/2;

        int left = findSubArray(l, mid, nums);
        int right = findSubArray(mid+1, r, nums);

        int sum = 0, bestLeft = INT_MIN;
        for(int i = mid; i >= l; --i){
            sum += nums[i];
            bestLeft = max(bestLeft, sum);
        }

        sum = 0;
        int bestRight = INT_MIN;
        for(int i = mid+1; i <= r; ++i){
            sum += nums[i];
            bestRight = max(bestRight, sum);
        }

        int cross = bestLeft + bestRight;

        return max({left, right, cross});
    }

    int maxSubArray(vector<int>& nums) {
        return findSubArray(0, nums.size() - 1, nums);
    }
};
```