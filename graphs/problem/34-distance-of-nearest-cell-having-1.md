```cpp
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if(distance[nx][ny] != INT_MAX)
                    continue;

                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return distance;
    }
};
```