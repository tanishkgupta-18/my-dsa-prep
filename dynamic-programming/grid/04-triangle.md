```cpp
class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle) {
        // Base Case: Reached the last row
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        // Move to the next row: either same index or index + 1
        int down = helper(i + 1, j, triangle);
        int diagonal = helper(i + 1, j + 1, triangle);

        return triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(0, 0, triangle);
    }
};
```

```cpp
class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle) {
        // Base Case: Reached the last row
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        // Move to the next row: either same index or index + 1
        int down = helper(i + 1, j, triangle);
        int diagonal = helper(i + 1, j + 1, triangle);

        return triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(0, 0, triangle);
    }
};
```