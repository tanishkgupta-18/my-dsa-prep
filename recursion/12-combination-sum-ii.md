```cpp
class Solution {
public:
    void helper(int start, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& ans, int target) {
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0) return;

        for(int i = start ; i < candidates.size() ; ++i){
            if(i > start && candidates[i] == candidates[i-1]) continue;

            curr.push_back(candidates[i]);
            helper(i+1, curr, candidates, ans, target - candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, candidates, ans, target);
        return ans;
    }
};
```