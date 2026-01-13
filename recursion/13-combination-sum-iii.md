```cpp
class Solution {
public:
    void helper(int i, int k, int target, vector<int>& curr, vector<vector<int>>& ans) {

        if (curr.size() == k) {
            if (target == 0) ans.push_back(curr);
            return;
        }

        if (i > 9 || target < 0) return;

        // take
        curr.push_back(i);
        helper(i + 1, k, target - i, curr, ans);
        curr.pop_back();

        // skip
        helper(i + 1, k, target, curr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(1, k, n, curr, ans);
        return ans;
    }
};
```