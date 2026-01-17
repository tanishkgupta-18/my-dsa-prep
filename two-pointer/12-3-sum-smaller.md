```cpp
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0 ; i < n; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s >= target) --right;
                else {
                    ans += right - left;
                    ++left;
                }
            }
        }
        return ans;
    }
};
```