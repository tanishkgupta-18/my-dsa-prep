```cpp
class Solution {
  public:
    bool solve(Node* p1, Node* p2){
        if(!p1 && !p2) return true;
        if(!p1 || !p2) return false;
        
        bool res1 = solve(p1->left, p2->right);
        bool res2 = solve(p1->right, p2->left);
        
        return (p1->data == p2->data) && (res1 && res2);
    }
    bool isSymmetric(Node* root) {
        if (!root) return true;
        return solve(root->left, root->right);
    }
};
```