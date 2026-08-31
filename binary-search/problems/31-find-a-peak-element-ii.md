```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find maximum element in column mid
            int maxRow = 0;

            for (int row = 1; row < m; row++) {
                if (mat[row][mid] > mat[maxRow][mid]) {
                    maxRow = row;
                }
            }

            int curr = mat[maxRow][mid];

            int left = (mid > 0)
                       ? mat[maxRow][mid - 1]
                       : -1;

            int right = (mid < n - 1)
                        ? mat[maxRow][mid + 1]
                        : -1;

            // Peak found
            if (curr > left && curr > right) {
                return {maxRow, mid};
            }

            // Move toward the larger neighbor
            if (right > curr) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
```