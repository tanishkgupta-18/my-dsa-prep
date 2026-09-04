```cpp
class Solution {
public:
    vector<string> ans;

    int dr[4] = {1, 0, 0, -1};
    int dc[4] = {0, -1, 1, 0};
    char dir[4] = {'D', 'L', 'R', 'U'};

    void dfs(int r, int c, int n,
             vector<vector<int>>& maze,
             string& path) {

        // Reached destination
        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        for (int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            // Valid and unvisited
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                maze[nr][nc] == 1) {

                // Choose
                maze[nr][nc] = 0;
                path.push_back(dir[d]);

                // Explore
                dfs(nr, nc, n, maze, path);

                // Undo
                path.pop_back();
                maze[nr][nc] = 1;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return {};

        string path;

        // Mark starting cell visited
        maze[0][0] = 0;

        dfs(0, 0, n, maze, path);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
```