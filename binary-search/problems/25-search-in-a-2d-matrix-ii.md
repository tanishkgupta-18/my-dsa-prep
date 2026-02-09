```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0, c = cols-1;
        while(c >= 0 && r < rows){
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) c--;
            else r++;
        }

        return false;
    }
};
```