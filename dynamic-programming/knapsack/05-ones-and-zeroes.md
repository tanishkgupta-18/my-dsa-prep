```cpp
class Solution {
    // 3D Memo: memo[index][m][n]
    int memo[601][101][101];

public:
    int f(int i, vector<string>& strs, int m, int n) {
        // Base Case
        if (i < 0) return 0;
        if (memo[i][m][n] != -1) return memo[i][m][n];

        // 1. Skip current string
        int skip = f(i - 1, strs, m, n);

        // 2. Pick current string (if budget allows)
        int pick = 0;
        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            else ones++;
        }

        if (m >= zeros && n >= ones) {
            // We add 1 to the count and subtract costs from m and n
            pick = 1 + f(i - 1, strs, m - zeros, n - ones);
        }

        return memo[i][m][n] = max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize memo with -1
        memset(memo, -1, sizeof(memo));
        return f(strs.size() - 1, strs, m, n);
    }
};
```