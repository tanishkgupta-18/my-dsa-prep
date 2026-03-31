```cpp
class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights,
                       int src, int dst, int K) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {cost, node, stops}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(K+2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;

            if (stops > K) continue;

            for (auto &[v, w] : adj[u]) {
                int newCost = cost + w;

                if (newCost < dist[v][stops + 1]) {
                    dist[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
```