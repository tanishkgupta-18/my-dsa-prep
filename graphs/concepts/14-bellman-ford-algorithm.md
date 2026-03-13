```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < n - 1; i++){
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect negative cycle
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Negative weight cycle detected\n";
            return {};
        }
    }

    return dist;
}

int main(){

    int n = 4;

    vector<vector<int>> edges = {
        {0,1,1},
        {0,2,4},
        {1,2,-3},
        {1,3,2},
        {2,3,3}
    };

    vector<int> dist = bellmanFord(n, edges, 0);

    for(int d : dist)
        cout << d << " ";

}
```