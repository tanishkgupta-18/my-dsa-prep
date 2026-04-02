```cpp
class Solution {
  public:
    int solve(Node* root, int& maxSum){
        if(!root) return 0;
        
        // handle negative values
        int ls = max(0, solve(root->left, maxSum));
        int rs = max(0, solve(root->right, maxSum));
        
        maxSum = max(maxSum, root->data + ls + rs);
        
        return root->data + max(ls, rs); 
    }

    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        
        return maxSum;
    }
};
```