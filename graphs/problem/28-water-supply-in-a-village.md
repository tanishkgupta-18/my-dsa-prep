```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {

    vector<tuple<int, int, int>> edges;

    // ? Add wells (virtual node 0)
    for(int i = 1; i <= n; i++) {
        edges.push_back({wells[i-1], 0, i});
    }

    // ? Add pipes
    for(auto &p : pipes) {
        edges.push_back({p[2], p[0], p[1]});
    }

    // Sort edges
    sort(edges.begin(), edges.end());

    DisjointSet ds(n);
    int totalCost = 0;

    for(auto &[cost, u, v] : edges) {
        if(ds.findUPar(u) != ds.findUPar(v)) {
            totalCost += cost;
            ds.unionByRank(u, v);
        }
    }

    return totalCost;
}
```