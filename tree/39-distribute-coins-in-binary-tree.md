```cpp
class Solution {
public:
    int countMoves(TreeNode* root, int& moves){
        if(!root) return 0;

        int left = countMoves(root->left, moves);
        int right = countMoves(root->right, moves);

        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        countMoves(root, moves);
        return moves;
    }
};
```