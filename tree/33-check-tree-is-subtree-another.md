```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* node, TreeNode* subRoot){
        if(!node && !subRoot) return true;
        if(!node || !subRoot) return false;

        return (node->val == subRoot->val) && check(node->left, subRoot->left) && check(node->right, subRoot->right); 
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root->val == subRoot->val){
            if(check(root, subRoot)) return true;
        }

        bool left = false;
        if(root->left) left = solve(root->left, subRoot);
        bool right = false;
        if(root->right) right = solve(root->right, subRoot);

        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;

        return solve(root, subRoot);
    }
};
```