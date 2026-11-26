```cpp
class Solution {
public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Traverse the current diagonal using right pointers
            while (curr != NULL) {
                ans.push_back(curr->data);

                // Left child belongs to the next diagonal
                if (curr->left != NULL) {
                    q.push(curr->left);
                }

                // Right child belongs to the same diagonal
                curr = curr->right;
            }
        }

        return ans;
    }
};
```