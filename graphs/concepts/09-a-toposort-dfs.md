```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj,
         vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;

    for(int v : adj[u])
    {
        if(!vis[v])
            dfs(v, adj, vis, st);
    }

    // push after visiting neighbors
    st.push(u);
}

void topoSort(int V, vector<vector<int>> &adj)
{
    vector<bool> vis(V, false);
    stack<int> st;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            dfs(i, adj, vis, st);
    }

    // print topological order
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topoSort(V, adj);
}
```