```cpp
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        // {time, x, y, moveType}
        priority_queue<
            tuple<int, int, int, int>,
            vector<tuple<int, int, int, int>>,
            greater<tuple<int, int, int, int>>
        > pq;

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(2, INT_MAX))
        );

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [time, x, y, moveType] = pq.top();
            pq.pop();

            if (time > dist[x][y][moveType])
                continue;

            if (x == n - 1 && y == m - 1)
                return time;

            int moveCost = (moveType == 0) ? 1 : 2;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int newTime = max(time, moveTime[nx][ny]) + moveCost;
                int nextMove = 1 - moveType;

                if (newTime < dist[nx][ny][nextMove]) {
                    dist[nx][ny][nextMove] = newTime;
                    pq.push({newTime, nx, ny, nextMove});
                }
            }
        }

        return -1;
    }
};
```