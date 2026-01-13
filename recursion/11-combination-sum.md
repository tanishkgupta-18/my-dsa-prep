```cpp
class Solution {
public:
    void helper(int i, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& ans, int target) {

        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i == candidates.size() || target < 0) return;

        // pick
        curr.push_back(candidates[i]);
        helper(i, curr, candidates, ans, target - candidates[i]);
        curr.pop_back();

        // not pick
        helper(i + 1, curr, candidates, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, candidates, ans, target);
        return ans;
    }
};
```