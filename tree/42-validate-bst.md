```cpp

class Solution {
public:
    bool solve(TreeNode* root, long long min_value, long long max_value) {
        if (!root) return true;

        if (root->val <= min_value || root->val >= max_value)
            return false;

        bool left_subtree = solve(root->left, min_value, root->val);

        bool right_subtree = solve(root->right, root->val, max_value);

        return left_subtree && right_subtree;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

```