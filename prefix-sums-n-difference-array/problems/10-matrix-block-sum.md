```cpp
class Solution {
public:
    int getSum(vector<vector<int>>& pref, int r1, int c1, int r2, int c2) {
        return pref[r2+1][c2+1] 
             - pref[r1][c2+1] 
             - pref[r2+1][c1] 
             + pref[r1][c1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m+1, vector<int>(n+1, 0));

        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                pref[i][j] = mat[i-1][j-1] 
                           + pref[i-1][j] 
                           + pref[i][j-1] 
                           - pref[i-1][j-1]; 
            }
        }

        vector<vector<int>> answer(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                
                int r1 = max(0, i-k);
                int c1 = max(0, j-k);
                int r2 = min(m-1, i+k);
                int c2 = min(n-1, j+k);

                answer[i][j] = getSum(pref, r1, c1, r2, c2);
            }
        }

        return answer;
    }
};
```