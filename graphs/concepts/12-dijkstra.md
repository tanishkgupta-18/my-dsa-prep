```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src)
{
    vector<int> dist(V, INT_MAX);

    // min heap -> {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // outdated entry
        if(d > dist[u]) continue;

        for(auto &[v, w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,50});
    adj[0].push_back({2,100});

    adj[1].push_back({0,50});
    adj[1].push_back({2,30});
    adj[1].push_back({3,200});

    adj[2].push_back({0,100});
    adj[2].push_back({1,30});
    adj[2].push_back({3,20});

    adj[3].push_back({1,200});
    adj[3].push_back({2,20});

    vector<int> ans = dijkstra(V, adj, 0);

    for(int x : ans)
        cout << x << " ";

    return 0;
}
```