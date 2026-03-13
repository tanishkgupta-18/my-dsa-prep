```cpp
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        vector<pair<int,pair<int,int>>> edges;

        for(int i = 0; i < V; i++) {
            for(auto &it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];

                if(i < adjNode)   // avoid duplicate edges
                    edges.push_back({wt,{i,adjNode}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mstWeight = 0;

        for(auto &it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)) {
                mstWeight += wt;
                ds.unionByRank(u,v);
            }
        }

        return mstWeight;
    }
};
```