```cpp
Node* solve(vector<int>& preorder,
            unordered_map<int, int>& inMap,
            int& preIndex,
            int inStart,
            int inEnd) {

    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int index = inMap[rootVal];

    root->left = solve(preorder, inMap, preIndex, inStart, index - 1);
    root->right = solve(preorder, inMap, preIndex, index + 1, inEnd);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
    unordered_map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    return solve(preorder, inMap, preIndex, 0, inorder.size() - 1);
}
```