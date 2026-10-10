```cpp
long long prev = LLONG_MIN;

bool inorder(TreeNode* root) {
    if (root == nullptr) return true;

    if (!inorder(root->left))
        return false;

    if (root->val <= prev)
        return false;

    prev = root->val;

    return inorder(root->right);
}
```