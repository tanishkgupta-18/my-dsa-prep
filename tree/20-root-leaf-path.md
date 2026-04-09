```cpp
class Solution {
public:
    void solve(Node* root, vector<int>& arr, vector<vector<int>>& res) {
        if (!root) return;

        arr.push_back(root->data);

        if (!root->left && !root->right) {
            res.push_back(arr);
        } else {
            solve(root->left, arr, res);
            solve(root->right, arr, res);
        }

        // backtrack
        arr.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> arr;
        solve(root, arr, res);
        return res;
    }
};
```