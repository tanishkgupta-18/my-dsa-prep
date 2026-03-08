## To find the shortest path in a graph where edge weights are only 0 or 1.

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void zeroOneBFS(int n, int s, vector<vector<pair<int,int>>> &adj) {
    vector<int> d(n, INF);
    d[s] = 0;

    deque<int> q;
    q.push_front(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;

            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;

                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << d[i] << endl;
    }
}

int main() {

    int n = 5; // number of nodes
    vector<vector<pair<int,int>>> adj(n);

    // Example edges (u -> v, weight)
    adj[0].push_back({1,0});
    adj[0].push_back({2,1});
    adj[1].push_back({2,1});
    adj[1].push_back({3,0});
    adj[2].push_back({3,1});
    adj[3].push_back({4,0});

    int source = 0;

    zeroOneBFS(n, source, adj);

    return 0;
}
```