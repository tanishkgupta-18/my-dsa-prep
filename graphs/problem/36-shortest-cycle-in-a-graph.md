```cpp
class Solution {
public:
    int bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n, -1);
        vector<int> parent(n, -1);

        queue<int> q;

        dist[start] = 0;
        q.push(start);

        int minCycle = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
                else if (parent[u] != v) {
                    minCycle = min(minCycle,
                                   dist[u] + dist[v] + 1);
                }
            }
        }

        return minCycle;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int u = 0; u < n; ++u) {
            ans = min(ans, bfs(u, adj));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```