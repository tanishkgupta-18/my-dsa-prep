```cpp
class Solution {
public:

    bool bfs(int start, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                // If not colored → assign opposite color
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                // If same color → conflict
                else if(color[v] == color[u]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        // Build graph
        for(auto &d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, -1);

        // Handle disconnected components
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                if(!bfs(i, adj, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};
```