>Brute Force
```cpp
class Solution {
public:
    bool checkPal(string t){
        int i = 0;
        int j = t.size()-1;

        while(i < j){
            if(t[i] != t[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(int start, int n, string s, vector<string> curr, vector<vector<string>>& ans){
        if(start == n){
            ans.push_back(curr);
            return;
        }

        for(int len = 1 ; len <= n-start ; ++len){
            string t = s.substr(start, len);

            if(checkPal(t)){
                curr.push_back(t);
                solve(start+len, n, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, n, s, curr, ans);

        return ans;
    }
};
```

>Optimal Solution
```cpp
class Solution {
public:
    vector<vector<bool>> dp;

    void solve(int start, int n, string& s,
               vector<string>& curr,
               vector<vector<string>>& ans) {

        if(start == n) {
            ans.push_back(curr);
            return;
        }

        for(int len = 1; len <= n-start; len++) {

            int j = start + len - 1;

            if(dp[start][j]) {
                curr.push_back(s.substr(start, len));

                solve(j+1, n, s, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        dp.assign(n, vector<bool>(n, false));

        // Precompute palindrome substrings
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j]) {
                    if(j-i <= 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> curr;

        solve(0, n, s, curr, ans);

        return ans;
    }
};
```