```cpp
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        
        // Base Case: Out of bounds OR current pixel does not match the starting pixel's original color
        if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != originalColor) {
            return;
        }
        
        // Change the color of the current pixel
        image[r][c] = newColor;
        
        // Recursively look in all 4 cardinal directions
        dfs(image, r - 1, c, originalColor, newColor); // Up
        dfs(image, r + 1, c, originalColor, newColor); // Down
        dfs(image, r, c - 1, originalColor, newColor); // Left
        dfs(image, r, c + 1, originalColor, newColor); // Right
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        // Avoid infinite loops: Only start DFS if the target color is actually different
        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }
        
        return image;
    }
};
```

```cpp
#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        
        // Edge case check
        if (originalColor == color) return image;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color; // Color the starting pixel immediately
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Look in all 4 directions
            for (int i = 0; i < 4; i++) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                // If within bounds and matches the original color
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && image[nRow][nCol] == originalColor) {
                    image[nRow][nCol] = color; // Update color
                    q.push({nRow, nCol});      // Push to queue to check its neighbors later
                }
            }
        }
        
        return image;
    }
};
```