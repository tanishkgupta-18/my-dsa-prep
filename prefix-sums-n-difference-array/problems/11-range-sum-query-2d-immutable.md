```cpp
class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        pref = vector<vector<int>>(N+1, vector<int>(M+1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                pref[i][j] = matrix[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2+1][col2+1] - pref[row1][col2+1] - pref[row2+1][col1] + pref[row1][col1];
    }
};
```