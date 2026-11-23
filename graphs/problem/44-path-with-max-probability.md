```cpp
class Solution {
public:
    double maxProbability(
        int n,
        vector<vector<int>>& edges,
        vector<double>& succProb,
        int start,
        int end
    ) {

        vector<vector<pair<int, double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        // Max heap: {probability, node}
        priority_queue<
            pair<double, int>
        > pq;

        vector<double> prob(n, 0.0);

        prob[start] = 1.0;
        pq.push({1.0, start});

        while(!pq.empty()) {

            auto [currProb, u] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if(currProb < prob[u])
                continue;

            if(u == end)
                return currProb;

            for(auto &[v, edgeProb] : adj[u]) {

                double newProb = currProb * edgeProb;

                if(newProb > prob[v]) {
                    prob[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;
    }
};
```