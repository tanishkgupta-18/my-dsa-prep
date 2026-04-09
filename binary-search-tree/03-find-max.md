## Iterative Approach

```cpp
Node* findMax(Node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
```

## Recursive Approach

```cpp
Node* findMax(Node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findMax(root->right);
}
```