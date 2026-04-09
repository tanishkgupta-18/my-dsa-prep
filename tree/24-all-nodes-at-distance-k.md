```cpp
class Solution {
public:
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        queue<Node*> q;

        q.push(root);

        // Step 1: Build parent map
        while (!q.empty()) {
            Node* node = q.front(); q.pop();

            if (node->data == target) targetNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS from target
        vector<int> res;
        unordered_map<Node*, bool> visited;
        queue<pair<Node*, int>> bfs;

        bfs.push({targetNode, 0});
        visited[targetNode] = true;

        while (!bfs.empty()) {
            auto [node, dist] = bfs.front();
            bfs.pop();

            if (dist == k) res.push_back(node->data);

            if (dist > k) break;

            if (node->left && !visited[node->left]) {
                bfs.push({node->left, dist + 1});
                visited[node->left] = true;
            }

            if (node->right && !visited[node->right]) {
                bfs.push({node->right, dist + 1});
                visited[node->right] = true;
            }

            if (parent[node] && !visited[parent[node]]) {
                bfs.push({parent[node], dist + 1});
                visited[parent[node]] = true;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
```