```cpp
class Solution {
public:
    void helper(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        ans.push_back(curr);

        for(int i = start ; i < nums.size() ; ++i){
            if(i > start && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);

            helper(i+1, nums, curr, ans);

            curr.pop_back();
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;

        helper(0, nums, curr, ans);

        return ans;
    }
};
```