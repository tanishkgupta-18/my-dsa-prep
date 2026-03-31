```cpp
class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        const int INF = 1e9;

        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INF));

        // min heap → {effort, row, col}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<pair<int,int>> dirs = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            // IMPORTANT (skip outdated)
            if (effort > dist[r][c]) continue;

            // destination reached
            if (r == n-1 && c == m-1) return effort;

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int newEffort = max(
                    effort,
                    abs(mat[nr][nc] - mat[r][c])
                );

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};
```