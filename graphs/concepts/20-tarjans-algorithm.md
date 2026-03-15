```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& inStack,
             stack<int>& st,
             vector<vector<int>>& scc,
             int& timer) {

        disc[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = true;

        for(int nei : adj[node]) {

            if(disc[nei] == -1) {

                dfs(nei, adj, disc, low, inStack, st, scc, timer);

                low[node] = min(low[node], low[nei]);
            }
            else if(inStack[nei]) {
                low[node] = min(low[node], disc[nei]);
            }
        }

        // root of SCC
        if(low[node] == disc[node]) {

            vector<int> component;

            while(true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;

                component.push_back(v);

                if(v == node) break;
            }

            scc.push_back(component);
        }
    }

    vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);

        stack<int> st;
        vector<vector<int>> scc;

        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(disc[i] == -1)
                dfs(i, adj, disc, low, inStack, st, scc, timer);
        }

        return scc;
    }
};
```