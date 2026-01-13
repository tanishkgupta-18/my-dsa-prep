```cpp
class Solution {
public:
    int findMajor(int l, int r, vector<int>& nums){
        if(l == r) return nums[l];

        int mid = l + (r-l)/2;

        int leftMajor = findMajor(l, mid, nums);
        int rightMajor = findMajor(mid+1, r, nums);

        if(leftMajor == rightMajor) return leftMajor;

        int leftCount = 0, rightCount = 0;

        for(int i = l ; i <= r ; ++i){
            if(leftMajor == nums[i]) leftCount++;
            if(rightMajor == nums[i]) rightCount++;
        } 

        return (leftCount > rightCount) ? leftMajor : rightMajor;
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        return findMajor(0, n-1, nums);
    }
};
```