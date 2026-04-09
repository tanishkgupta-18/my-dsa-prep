```cpp
class Solution {
  public:
    int findCeil(Node* root, int x) {
        if(root == NULL) return -1;
        
        int ans = -1;
        while(root){
            if(root->data == x) return x;
            
            if(root->data < x){
                root = root->right;
            }else{
                ans = root->data;
                root = root->left;
            }
        }
        
        return ans;
    }
};
```