```cpp
class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(int index,
               string &s,
               vector<string> &path,
               vector<vector<string>> &ans) {

        // partition complete
        if(index == s.length()) {
            ans.push_back(path);
            return;
        }

        // try every substring starting from index
        for(int end = index; end < s.length(); end++) {

            // if palindrome
            if(isPalindrome(s, index, end)) {

                // choose
                path.push_back(s.substr(index, end - index + 1));

                // explore
                solve(end + 1, s, path, ans);

                // backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(0, s, path, ans);

        return ans;
    }
};
```