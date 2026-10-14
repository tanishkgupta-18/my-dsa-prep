```cpp
class Solution {
public:
    void dfs(TreeNode* root, int targetSum,
             vector<int>& path,
             vector<vector<int>>& ans) {

        if (root == nullptr)
            return;

        // choose current node
        path.push_back(root->val);
        targetSum -= root->val;

        // if leaf and required sum is achieved
        if (root->left == nullptr &&
            root->right == nullptr &&
            targetSum == 0) {

            ans.push_back(path);
        }

        // explore
        dfs(root->left, targetSum, path, ans);
        dfs(root->right, targetSum, path, ans);

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};
```