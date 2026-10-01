```cpp
class Solution {
    const int MOD = 1e9 + 7;
    int A, C, E;
    vector<vector<int>> dp;          // dp[day][city], -1 = not computed
    vector<vector<bool>> blocked;    // blocked[day][city]

    int solve(int day, int city) {
        if (blocked[day][city]) return 0;   // can't be here on this day
        if (day == C) return 1;             // completed a valid tour

        int &res = dp[day][city];
        if (res != -1) return res;

        long long ways = 0;
        for (int next = max(1, city - E); next <= min(A, city + E); next++) {
            ways += solve(day + 1, next);
        }
        return res = ways % MOD;
    }

  public:
    int countTours(int A, int B, int C, int E, vector<vector<int>>& D) {
        this->A = A; this->C = C; this->E = E;

        dp.assign(C + 1, vector<int>(A + 1, -1));
        blocked.assign(C + 1, vector<bool>(A + 1, false));

        for (auto &d : D) blocked[d[0]][d[1]] = true;   // d[0] = day, d[1] = city

        return solve(1, B);
    }
};
```