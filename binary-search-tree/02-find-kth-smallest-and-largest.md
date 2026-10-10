>Kth smallest
```cpp
class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
```

>Kth Largest
```cpp
class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void reverseInorder(TreeNode* root, int k) {
        if (root == nullptr) return;

        reverseInorder(root->right, k);

        cnt++;

        if (cnt == k) {
            ans = root->val;
            return;
        }

        reverseInorder(root->left, k);
    }

    int kthLargest(TreeNode* root, int k) {
        reverseInorder(root, k);
        return ans;
    }
};
```