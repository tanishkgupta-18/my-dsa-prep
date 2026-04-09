## Iterative Approach

```cpp
Node* findMin(Node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
```

## Recursive Approach

```cpp
Node* findMin(Node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findMin(root->left);
}
```