```cpp
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        int k = specialRoads.size();

        // Remove special roads that are not better than normal walking.
        vector<vector<int>> roads;

        for (auto& r : specialRoads) {
            int normal = abs(r[0] - r[2]) + abs(r[1] - r[3]);

            if (r[4] < normal) {
                roads.push_back(r);
            }
        }

        k = roads.size();

        // {cost, x, y}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Distance to each special road's starting point.
        vector<int> dist(k, INT_MAX);

        pq.push({0, start[0], start[1]});

        int ans = abs(start[0] - target[0]) +
                  abs(start[1] - target[1]);

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            // Directly reach target.
            ans = min(ans, cost +
                abs(x - target[0]) + abs(y - target[1]));

            for (int i = 0; i < k; i++) {
                auto& r = roads[i];

                // Walk to the starting point of special road.
                int newCost = cost +
                    abs(x - r[0]) + abs(y - r[1]);

                // Use special road.
                newCost += r[4];

                if (newCost < dist[i]) {
                    dist[i] = newCost;

                    pq.push({newCost, r[2], r[3]});
                }
            }
        }

        return ans;
    }
};
```