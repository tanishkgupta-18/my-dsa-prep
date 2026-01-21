```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> mx, mn;

        int l = 0, maxLength = 0;
        for(int r = 0 ; r < n ; ++r){
            while(!mx.empty() && nums[mx.back()] < nums[r]) mx.pop_back();
            mx.push_back(r); 

            while(!mn.empty() && nums[mn.back()] > nums[r]) mn.pop_back();
            mn.push_back(r);

            while(nums[mx.front()] - nums[mn.front()] > limit){
                l++;
                while(!mx.empty() && mx.front() < l) mx.pop_front();
                while(!mn.empty() && mn.front() < l) mn.pop_front();
            }

            maxLength = max(maxLength, r-l+1);
        }

        return maxLength;
    }
};
```