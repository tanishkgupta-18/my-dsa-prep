```cpp
class Solution {
public:
    unordered_map<int, int> index;
    vector<vector<int>> dp;
    int n;

    bool solve(int i, int k, vector<int>& stones) {

        if(i == n-1)
            return true;

        if(dp[i][k] != -1)
            return dp[i][k];

        for(int jump = k-1; jump <= k+1; ++jump) {

            if(jump <= 0)
                continue;

            int next_position = stones[i] + jump;

            if(index.find(next_position) != index.end()) {

                if(solve(index[next_position], jump, stones))
                    return dp[i][k] = true;
            }
        }

        return dp[i][k] = false;
    }

    bool canCross(vector<int>& stones) {

        n = stones.size();

        if(n == 1) return true;

        if(stones[1] != 1)
            return false;

        for(int i = 0; i < n; ++i)
            index[stones[i]] = i;

        dp.assign(n, vector<int>(n+1, -1));

        return solve(0, 0, stones);
    }
};
```