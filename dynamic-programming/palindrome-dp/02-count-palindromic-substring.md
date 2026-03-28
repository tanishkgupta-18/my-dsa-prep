```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // length = 1
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            count++;
        }

        // length = 2
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                count++;
            }
        }

        // length >= 3
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};
```

```cpp
class Solution {
public:
    int checkPalindrome(int i, int j, string& s, vector<vector<int>>& memo){
        if(i >= j) return true;

        if(memo[i][j] != -1) return memo[i][j];

        if(s[i] == s[j]) return memo[i][j] = checkPalindrome(i+1, j-1, s, memo);
        else memo[i][j] = 0;

        return memo[i][j];
    }

    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<int>> memo(n, vector<int>(n, -1));
        int count = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                if(checkPalindrome(i, j, s, memo)) count++;
            }
        }

        return count;
    }
};
```