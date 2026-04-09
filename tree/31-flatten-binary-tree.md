> This trick works on when order needed in preorder
```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // Find rightmost node of left subtree
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Attach right subtree
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = NULL;
            }

            // Move forward
            curr = curr->right;
        }
    }
};
```

## Recursive Approach
```cpp
class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
```

## Universal Approach
> this solution fits everywhere is universal converter
```cpp
TreeNode* prev = NULL;

void dfs(TreeNode* root) {
    if (!root) return;

    // 1. Traverse (depends on requirement)
    dfs(root->right);
    dfs(root->left);

    // 2. Modify pointers
    root->right = prev;
    root->left = NULL;

    // 3. Move prev
    prev = root;
}
```