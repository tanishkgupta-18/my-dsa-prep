```cpp
class Solution {
public:
    int cameras = 0;

    enum State {
        NEEDS_CAMERA,
        HAS_CAMERA,
        COVERED
    };

    State solve(TreeNode* root) {
        if (!root) return COVERED;

        State left = solve(root->left);
        State right = solve(root->right);

        // If any child is not covered,
        // place camera at current node.
        if (left == NEEDS_CAMERA || right == NEEDS_CAMERA) {
            cameras++;
            return HAS_CAMERA;
        }

        // If any child has a camera,
        // current node is already covered.
        if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return COVERED;
        }

        // Both children are covered,
        // but neither has a camera to cover current node.
        return NEEDS_CAMERA;
    }

    int minCameraCover(TreeNode* root) {
        if (solve(root) == NEEDS_CAMERA) {
            cameras++;
        }

        return cameras;
    }
};
```