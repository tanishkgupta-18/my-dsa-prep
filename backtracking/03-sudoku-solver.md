```cpp
class Solution {
public:

    bool isValid(int r, int c, char num,
                 vector<vector<char>>& board) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[r][j] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == num)
                return false;
        }

        // Check 3 x 3 box
        int startRow = (r / 3) * 3;
        int startCol = (c / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find an empty cell
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {

                    // Try 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(r, c, num, board)) {

                            // Choose
                            board[r][c] = num;

                            // Explore
                            if (solve(board))
                                return true;

                            // Undo
                            board[r][c] = '.';
                        }
                    }

                    // No number worked for this cell
                    return false;
                }
            }
        }

        // No empty cells -> solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
```