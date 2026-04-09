```cpp
class Solution {
public:
    unordered_map<int, int> inMap;
    int postIndex;

    Node* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        Node* root = new Node(rootVal);

        int index = inMap[rootVal];

        // IMPORTANT: build right first
        root->right = build(postorder, index + 1, inEnd);
        root->left = build(postorder, inStart, index - 1);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};
```