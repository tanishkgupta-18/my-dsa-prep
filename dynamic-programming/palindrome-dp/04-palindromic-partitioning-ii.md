>Brute
```cpp
class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string& s) {
        int n = s.size();

        if(i == n) return 0;

        int ans = INT_MAX;

        for(int j = i; j < n; j++) {
            if(isPal(s, i, j)) {
                ans = min(ans, 1 + solve(j+1, s));
            }
        }

        return ans;
    }

    int minCut(string s) {
        return solve(0, s) - 1;
    }
};
```

```cpp
class Solution {
public:
    vector<int> dp;
    vector<vector<bool>> pal;

    int solve(int i, string& s) {
        int n = s.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int j = i; j < n; j++) {
            if(pal[i][j]) {
                ans = min(ans, 1 + solve(j+1, s));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();

        dp.assign(n, -1);
        pal.assign(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j]) {
                    pal[i][j] = (j-i <= 2) || pal[i+1][j-1];
                }
            }
        }

        return solve(0, s) - 1;
    }
};
```

```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute palindromes
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j]) {
                    pal[i][j] = (j-i <= 2) || pal[i+1][j-1];
                }
            }
        }

        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(pal[j][i]) {
                    dp[i+1] = min(dp[i+1], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
```

```cpp
class Solution {
public:
    void expand(int l, int r, string& s, vector<int>& dp) {
        int n = s.size();

        while(l >= 0 && r < n && s[l] == s[r]) {

            dp[r+1] = min(dp[r+1], dp[l] + 1);

            l--;
            r++;
        }
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;

        for(int i = 0; i < n; i++) {
            expand(i, i, s, dp);
            expand(i, i+1, s, dp);
        }

        return dp[n];
    }
};
```