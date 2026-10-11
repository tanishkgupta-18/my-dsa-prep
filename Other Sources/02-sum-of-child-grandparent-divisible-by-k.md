```cpp
int dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent, int k) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (grandparent != nullptr && grandparent->val % k == 0)
        sum += root->val;

    sum += dfs(root->left, root, parent, k);
    sum += dfs(root->right, root, parent, k);

    return sum;
}

int sumGrandparentDivisible(TreeNode* root, int k) {
    return dfs(root, nullptr, nullptr, k);
}
```