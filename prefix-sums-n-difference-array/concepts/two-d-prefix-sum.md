```cpp
// 1-based indexing example
int pref[N+1][M+1];
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
        pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
}

// Querying (r1, c1) to (r2, c2)
int getSum(int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
}
```