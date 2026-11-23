```cpp
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 0});
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        while(!pq.empty()){
            auto [time, x, y] = pq.top();
            pq.pop();

            if (time > dist[x][y]) continue;

            if (x == n - 1 && y == m - 1)
                return time;

            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int new_time = max(time, moveTime[nx][ny])+1;

                int room_time = moveTime[nx][ny];

                if(new_time < dist[nx][ny]){
                    dist[nx][ny] = new_time;
                    pq.push({new_time, nx, ny});
                }
            }
        }

        return -1;
    }
};
```