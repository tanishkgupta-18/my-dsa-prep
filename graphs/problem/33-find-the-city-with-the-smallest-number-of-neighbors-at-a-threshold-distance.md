```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a city to itself
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Fill direct edges
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(dist[i][via] == INF || dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][via] + dist[via][j]
                    );
                }
            }
        }

        int minReachable = INT_MAX;
        int answerCity = -1;

        // Count reachable cities for each city
        for(int city = 0; city < n; city++) {

            int reachableCount = 0;

            for(int neighbour = 0; neighbour < n; neighbour++) {
                if(dist[city][neighbour] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            // <= handles tie-breaking in favor of larger city number
            if(reachableCount <= minReachable) {
                minReachable = reachableCount;
                answerCity = city;
            }
        }

        return answerCity;
    }
};
```