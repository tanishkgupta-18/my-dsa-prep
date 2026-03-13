```cpp
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        static vector<pair<int,int>> dirs = {
            {0,1},{1,0},{0,-1},{-1,0}
        };

        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;

        int area = 0;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            area++;

            for(auto &[dx,dy] : dirs){
                int nx = x + dx;
                int ny = y + dy;

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                    grid[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea, bfs(i,j,grid));
                }
            }
        }

        return maxArea;
    }
};
```