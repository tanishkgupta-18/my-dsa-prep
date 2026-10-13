```cpp
class Solution {
public:
    void dfs(Node* root, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        // include current node in the path
        path.push_back(root->data);

        // if leaf node, store the complete root-to-leaf path
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        } else {
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }

        // backtrack: remove current node before returning
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, path, ans);

        return ans;
    }
};
```