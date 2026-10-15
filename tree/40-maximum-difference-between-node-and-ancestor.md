```cpp
class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mini, int maxi) {
        if (root == nullptr)
            return;

        ans = max(ans, abs(root->val - mini));
        ans = max(ans, abs(root->val - maxi));

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        dfs(root->left, mini, maxi);
        dfs(root->right, mini, maxi);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
```