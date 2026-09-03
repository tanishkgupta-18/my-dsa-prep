```cpp
class Solution {
public:
    void backtrack(int i, string& digits,
                   unordered_map<char, string>& mp,
                   string& curr,
                   vector<string>& ans) {

        if (i == digits.length()) {
            ans.push_back(curr);
            return;
        }

        for (char c : mp[digits[i]]) {
            curr.push_back(c);

            backtrack(i + 1, digits, mp, curr, ans);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        string curr;

        backtrack(0, digits, mp, curr, ans);

        return ans;
    }
};
```