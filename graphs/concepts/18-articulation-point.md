```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& visited,
             vector<bool>& isAP,
             int& timer) {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        int children = 0;

        for(int nei : adj[node]) {

            if(nei == parent) continue;

            if(!visited[nei]) {

                children++;
                dfs(nei, node, adj, disc, low, visited, isAP, timer);

                low[node] = min(low[node], low[nei]);

                // Case 1: root
                if(parent == -1 && children > 1)
                    isAP[node] = true;

                // Case 2: non-root
                if(parent != -1 && low[nei] >= disc[node])
                    isAP[node] = true;
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nei]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V), low(V);
        vector<bool> visited(V,false), isAP(V,false);

        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i])
                dfs(i, -1, adj, disc, low, visited, isAP, timer);
        }

        vector<int> ans;

        for(int i = 0; i < V; i++)
            if(isAP[i]) ans.push_back(i);

        if(ans.empty()) return {-1};

        return ans;
    }
};
```