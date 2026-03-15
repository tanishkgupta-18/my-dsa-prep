```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& vis,
             vector<vector<int>>& bridges,
             int& timer) {

        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(int nei : adj[node]) {

            if(nei == parent) continue;

            if(!vis[nei]) {

                dfs(nei, node, adj, disc, low, vis, bridges, timer);

                low[node] = min(low[node], low[nei]);

                // bridge condition
                if(low[nei] > disc[node]) {
                    bridges.push_back({node, nei});
                }
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nei]);
            }
        }
    }

    vector<vector<int>> findBridges(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V), low(V);
        vector<bool> vis(V,false);
        vector<vector<int>> bridges;

        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, disc, low, vis, bridges, timer);
            }
        }

        return bridges;
    }
};
```