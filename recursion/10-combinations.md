```cpp
class Solution {
public:
    void helper(int start, int n, vector<vector<int>>& ans, vector<int>& curr, int k){
        // available < needed
        if (n - start + 1 < k - curr.size()) return;

        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }

        for(int i = start ; i <= n ; ++i){
            curr.push_back(i);
            helper(i+1, n, ans, curr, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(1, n, ans, curr, k);
        return ans;
    }
};
```