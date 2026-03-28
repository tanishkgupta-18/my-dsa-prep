```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;

        // Push all land cells
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        // Edge case: all land or all water
        if(q.empty() || q.size() == n*n) return -1;

        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dist = -1;

        while(!q.empty()){
            int sz = q.size();
            dist++;

            while(sz--){
                auto [x, y] = q.front();
                q.pop();

                for(auto &d : dirs){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};
```