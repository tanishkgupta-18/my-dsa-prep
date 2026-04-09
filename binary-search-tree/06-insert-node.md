## Iterative Approach

```cpp
Node* insertIntoBST(Node* root, int val) {
    if (root == NULL) return new Node(val);

    Node* curr = root;

    while (true) {
        if (val < curr->data) {
            if (curr->left == NULL) {
                curr->left = new Node(val);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == NULL) {
                curr->right = new Node(val);
                break;
            } else {
                curr = curr->right;
            }
        }
    }

    return root;
}
```

## Recursive Approach

```cpp
Node* insertIntoBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);   // Create new node
    }

    if (val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
```