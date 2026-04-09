```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            ans = max(ans, end - start + 1);

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }
        }

        return ans;
    }
};
```