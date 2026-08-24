```cpp
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv)
            return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough cables to ever connect all computers
        if(connections.size() < n - 1)
            return -1;

        DSU dsu(n);

        for(auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            dsu.unionBySize(u, v);
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(dsu.findUPar(i) == i)
                components++;
        }

        return components - 1;
    }
};
```

```cpp
class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for(auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        return components - 1;
    }
};
```