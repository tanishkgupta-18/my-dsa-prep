```cpp
class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {

        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        vector<vector<bool>> vis(n, vector<bool>(n,false));

        queue<tuple<int,int,int>> q;
        q.push({sx, sy, 0});

        vis[sx][sy] = true;

        vector<pair<int,int>> dirs = {
            {2,1},{2,-1},{-2,1},{-2,-1},
            {1,2},{1,-2},{-1,2},{-1,-2}
        };

        while(!q.empty()) {

            auto [x,y,steps] = q.front();
            q.pop();

            if(x == tx && y == ty)
                return steps;

            for(auto [dx,dy] : dirs) {

                int nx = x + dx;
                int ny = y + dy;

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]) {

                    vis[nx][ny] = true;
                    q.push({nx,ny,steps+1});
                }
            }
        }

        return -1;
    }
};
```