```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;

        return dfs(root, 0, targetSum, prefix);
    }

    int dfs(TreeNode* root, long long currSum, int targetSum,
            unordered_map<long long, int>& prefix) {

        if (root == nullptr) return 0;

        currSum += root->val;

        int count = 0;

        if (prefix.find(currSum - targetSum) != prefix.end()) {
            count += prefix[currSum - targetSum];
        }

        prefix[currSum]++;

        count += dfs(root->left, currSum, targetSum, prefix);
        count += dfs(root->right, currSum, targetSum, prefix);

        prefix[currSum]--;

        return count;
    }
};
```