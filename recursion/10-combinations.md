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

```cpp
class Solution {
public:
    void solve(int start, int n, int k,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        if(start > n) return;

        // Pick
        curr.push_back(start);
        solve(start + 1, n, k, curr, ans);

        curr.pop_back();

        // Not Pick
        solve(start + 1, n, k, curr, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;

        solve(1, n, k, curr, ans);

        return ans;
    }
};
```
