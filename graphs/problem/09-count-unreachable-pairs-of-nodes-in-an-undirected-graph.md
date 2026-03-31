```cpp
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int findUPar(int node){
        if(node==parent[node])
            return node;

        return parent[node]=findUPar(parent[node]); // path compression
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;

        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v]=ulp_u;

        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto& e : edges){
            ds.unionByRank(e[0], e[1]);
        }

        vector<long long> count(n, 0);

        for(int i = 0 ; i < n ; ++i){
            int parent = ds.findUPar(i);
            count[parent]++;
        }

        long long cnt = 0;
        for(auto x : count){
            cnt += (x*(n-x));
        }

        return cnt/2; 
    }
};
```