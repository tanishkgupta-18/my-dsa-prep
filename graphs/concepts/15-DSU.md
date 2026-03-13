```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

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

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

// time complexity is O(1) for findUPar and O(1) for unionByRank and O(1) for unionBySize
// space complexity is O(n) where n is the number of nodes in the disjoint set.

int main(){
    DisjointSet ds(5);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    cout << ds.findUPar(1) << endl;
    cout << ds.findUPar(2) << endl;
    cout << ds.findUPar(3) << endl;
    cout << ds.findUPar(4) << endl;
    cout << ds.findUPar(5) << endl;
    return 0;
}
```