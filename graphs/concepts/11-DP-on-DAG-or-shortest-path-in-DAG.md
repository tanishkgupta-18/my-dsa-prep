```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void topoSort(int u, vector<vector<pair<int,int>>> &adj,
              vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;

    for(auto edge : adj[u])
    {
        int v = edge.first;

        if(!vis[v])
            topoSort(v, adj, vis, st);
    }

    st.push(u);
}

vector<int> shortestPathDAG(int V,
                            vector<vector<pair<int,int>>> &adj,
                            int src)
{
    stack<int> st;
    vector<bool> vis(V, false);

    // Topological sort
    for(int i = 0; i < V; i++)
        if(!vis[i])
            topoSort(i, adj, vis, st);

    vector<int> dist(V, INF);
    dist[src] = 0;

    // DP on DAG
    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        if(dist[u] != INF)
        {
            for(auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    return dist;
}

int main()
{
    int V = 6;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,2});
    adj[0].push_back({4,1});
    adj[1].push_back({2,3});
    adj[4].push_back({2,2});
    adj[4].push_back({5,4});
    adj[2].push_back({3,6});
    adj[5].push_back({3,1});

    int src = 0;

    vector<int> dist = shortestPathDAG(V, adj, src);

    for(int d : dist)
    {
        if(d == INF) cout << "INF ";
        else cout << d << " ";
    }
}
```