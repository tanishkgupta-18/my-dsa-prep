```cpp
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;

        // Step 1: Collect all 'O' cells located on the outer boundary
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if ((r == 0 || r == m - 1 || c == 0 || c == n - 1) && board[r][c] == 'O') {
                    q.push({r, c});
                    board[r][c] = 'E'; // Mark as 'Escaped' (border-connected)
                }
            }
        }

        // Step 2: BFS to mark all 'O's connected to border 'O's
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = 'E';
                    q.push({nr, nc});
                }
            }
        }

        // Step 3: Capture surrounded 'O's and restore safe 'E's back to 'O'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'E') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
```