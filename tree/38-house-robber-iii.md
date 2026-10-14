```cpp
class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Rob the current house
        int rob = root->val + left.second + right.second;

        // Do not rob the current house
        int notRob = max(left.first, left.second)
                   + max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};
```