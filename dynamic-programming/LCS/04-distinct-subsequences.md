```cpp
int solve(int i, int j, string &s, string &t) {
    if (j == t.size()) return 1;
    if (i == s.size()) return 0;

    int ans = solve(i + 1, j, s, t);

    if (s[i] == t[j]) {
        ans += solve(i + 1, j + 1, s, t);
    }

    return ans;
}
```

>Tabulation
```cpp
int solve(int i, int j, string &s, string &t,
          vector<vector<int>>& dp) {

    if (j == t.size()) return 1;
    if (i == s.size()) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    long long ans = solve(i + 1, j, s, t, dp);

    if (s[i] == t[j]) {
        ans += solve(i + 1, j + 1, s, t, dp);
    }

    return dp[i][j] = ans;
}
```