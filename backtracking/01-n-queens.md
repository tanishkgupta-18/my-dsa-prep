## Approach 1
```cpp
class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row,
               int n,
               vector<string>& board,
               unordered_set<int>& col,
               unordered_set<int>& diag1,
               unordered_set<int>& diag2) {

        // All rows have a queen
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check whether this position is safe
            if (col.count(c) ||
                diag1.count(row - c) ||
                diag2.count(row + c)) {
                continue;
            }

            // Place queen
            board[row][c] = 'Q';

            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            // Move to next row
            solve(row + 1, n, board,
                  col, diag1, diag2);

            // Backtrack
            board[row][c] = '.';

            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        solve(0, n, board, col, diag1, diag2);

        return ans;
    }
};
```

## Optimised Approach
```cpp
class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row, int n,
               vector<string>& board,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            int d1 = row - c + n - 1;
            int d2 = row + c;

            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            // choose
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // explore
            solve(row + 1, n, board,
                  col, diag1, diag2);

            // undo
            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, board, col, diag1, diag2);

        return ans;
    }
};
```