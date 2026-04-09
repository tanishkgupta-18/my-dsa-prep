```cpp
class Solution {
  public:
    int getLeftHeight(Node* root){
        int h = 0;
        
        while(root){
            h++;
            root = root->left;
        }
        
        return h;
    }
    
    int getRightHeight(Node* root){
        int h = 0;
        
        while(root){
            h++;
            root = root->right;
        }
        
        return h;
    }
    int countNodes(Node* root) {
        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);
        
        if(lh == rh)
            return (1 << lh) - 1;
            
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
## More Optimised Approach
```cpp
class Solution {
public:
    int getHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    // check if node exists at index idx in last level
    bool exists(int idx, int h, TreeNode* root) {
        int left = 0, right = (1 << (h - 1)) - 1;

        for (int i = 0; i < h - 1; i++) {
            int mid = left + (right - left) / 2;

            if (idx <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }

        return root != NULL;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = getHeight(root);

        if (h == 1) return 1;

        int low = 0, high = (1 << (h - 1)) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (exists(mid, h, root)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // nodes before last level + nodes in last level
        return (1 << (h - 1)) - 1 + low;
    }
};
```