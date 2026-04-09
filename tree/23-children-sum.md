```cpp
class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(!root || (!root->left && !root->right)) return true;
        
        int left = root->left? root->left->data : 0;
        int right = root->right? root->right->data :0;
        
        return (root->data == left + right) &&
               isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};
```