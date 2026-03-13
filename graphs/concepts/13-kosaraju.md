```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs1(int u, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[u] = 1;

        for(int v : adj[u]){
            if(!vis[v])
                dfs1(v, adj, vis, st);
        }

        st.push(u);
    }

    void dfs2(int u, vector<vector<int>>& adjT, vector<int>& vis, vector<int>& comp){
        vis[u] = 1;
        comp.push_back(u);

        for(int v : adjT[u]){
            if(!vis[v])
                dfs2(v, adjT, vis, comp);
        }
    }

    vector<vector<int>> kosaraju(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges)
            adj[e[0]].push_back(e[1]);

        stack<int> st;
        vector<int> vis(n,0);

        // Step 1: finish order
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs1(i, adj, vis, st);

        // Step 2: transpose graph
        vector<vector<int>> adjT(n);

        for(int u=0;u<n;u++)
            for(int v:adj[u])
                adjT[v].push_back(u);

        fill(vis.begin(), vis.end(), 0);

        vector<vector<int>> scc;

        // Step 3: process stack
        while(!st.empty()){
            int u = st.top();
            st.pop();

            if(!vis[u]){
                vector<int> comp;
                dfs2(u, adjT, vis, comp);
                scc.push_back(comp);
            }
        }

        return scc;
    }
};
```