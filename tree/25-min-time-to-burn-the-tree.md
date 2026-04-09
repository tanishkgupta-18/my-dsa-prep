```cpp
class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front(); q.pop();
            
            if(node->data == target) targetNode = node;
            
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
        unordered_map<Node*, bool> visited;
        queue<pair<Node*, int>> bfs;
        bfs.push({targetNode, 0});
        visited[targetNode] = true;
        
        int maxTime = 0;
        while(!bfs.empty()){
            auto [node, time] = bfs.front();
            bfs.pop();
            
            maxTime = max(maxTime, time);
            if(node->left && !visited[node->left]){
                bfs.push({node->left, time+1});
                visited[node->left] = true;
            }
            
            if(node->right && !visited[node->right]){
                bfs.push({node->right, time+1});
                visited[node->right] = true;
            }
            
            if(parent[node] && !visited[parent[node]]){
                bfs.push({parent[node], time+1});
                visited[parent[node]] = true;
            }
        }

        return maxTime;
    }
};
```