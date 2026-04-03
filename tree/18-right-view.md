```cpp
class Solution {
  public:
    vector<int> rightView(Node *root) {
        vector<int> res;
        if (!root) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // last node of this level
                if (i == size-1) {
                    res.push_back(node->data);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
        
    }
};
```