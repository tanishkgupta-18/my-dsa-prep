```cpp
class Solution {
public:
    bool check(string& s, string& t){
        if(s.size() == t.size()) return false;

        int mismatch = 0;
        int j = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            if(j >= t.size() || s[i] != t[j]) mismatch++;
            else j++;
        }

        return mismatch == 1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                if(check(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int ans = 0;
        for(auto x : dp)
            ans = max(ans, x);

        return ans;
    }
};
```