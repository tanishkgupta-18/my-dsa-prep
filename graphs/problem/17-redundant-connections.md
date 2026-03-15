```cpp
class DisjointSet{
    vector<int> parent, rank;

public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i = 0 ; i <= n ; ++i)
            parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else if(rank[ulp_v] > rank[ulp_u])
            parent[ulp_u] = ulp_v;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto& e : edges){
            int u = ds.findUPar(e[0]);
            int v = ds.findUPar(e[1]);

            if(u == v) return {e[0], e[1]};

            ds.unionByRank(e[0], e[1]);
        }

        return {};
    }
};
```