```cpp
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> nodes; // col -> last node
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            // overwrite every time → keeps last node
            nodes[col] = node->data;

            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        for (auto& it : nodes) {
            res.push_back(it.second);
        }

        return res;
    }
};
```