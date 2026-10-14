```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        // Leaf node check
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Short-circuits immediately if left branch succeeds
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};
```