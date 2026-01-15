```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0, right = n - 1, idx = n - 1;

        while(left <= right){
            int sqLeft = nums[left]*nums[left];
            int sqRight = nums[right]*nums[right];

            if(sqLeft >= sqRight){
                ans[idx--] = sqLeft;
                left++;
            } else {
                ans[idx--] = sqRight;
                right--;
            }
        }

        return ans;
    }
};
```