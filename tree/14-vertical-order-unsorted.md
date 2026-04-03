```cpp
class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        vector<vector<int>> res;

        if (!root) return res;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            mp[col].push_back(node->data);

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto& it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
```