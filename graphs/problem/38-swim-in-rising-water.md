```cpp
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto [time, x, y] = pq.top();
            pq.pop();

            if(time > dist[x][y]) continue;

            if(x == n-1 && y == n-1) return time;

            for(auto [dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int newTime = max(time, grid[nx][ny]);
                if(dist[nx][ny] > newTime){
                    dist[nx][ny] = newTime;
                    pq.push({newTime, nx, ny});
                }
            }
        }

        return -1;
    }
};
```