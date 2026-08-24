```cpp
class Solution {
public:

    static const int MOD = 1003;

    long long solve(
        int i,
        int j,
        int isTrue,
        string& s,
        vector<vector<vector<long long>>>& dp
    ) {

        // Base case
        if (i == j) {
            if (isTrue)
                return s[i] == 'T';

            return s[i] == 'F';
        }

        // Already calculated
        if (dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }

        long long ways = 0;

        // Try every operator
        for (int k = i + 1; k <= j - 1; k += 2) {

            char op = s[k];

            long long leftTrue =
                solve(i, k - 1, 1, s, dp);

            long long leftFalse =
                solve(i, k - 1, 0, s, dp);

            long long rightTrue =
                solve(k + 1, j, 1, s, dp);

            long long rightFalse =
                solve(k + 1, j, 0, s, dp);


            if (op == '&') {

                if (isTrue) {

                    ways += leftTrue * rightTrue;

                } else {

                    ways += leftTrue * rightFalse
                          + leftFalse * rightTrue
                          + leftFalse * rightFalse;
                }

            }

            else if (op == '|') {

                if (isTrue) {

                    ways += leftTrue * rightTrue
                          + leftTrue * rightFalse
                          + leftFalse * rightTrue;

                } else {

                    ways += leftFalse * rightFalse;
                }

            }

            else if (op == '^') {

                if (isTrue) {

                    ways += leftTrue * rightFalse
                          + leftFalse * rightTrue;

                } else {

                    ways += leftTrue * rightTrue
                          + leftFalse * rightFalse;
                }
            }

            ways %= MOD;
        }

        return dp[i][j][isTrue] = ways;
    }


    int countWays(int n, string s) {

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(
                n,
                vector<long long>(2, -1)
            )
        );

        return solve(0, n - 1, 1, s, dp);
    }
};
```