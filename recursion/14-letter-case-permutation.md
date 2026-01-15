```cpp
class Solution {
public:
    void helper(int i, string& s, vector<string>& ans){
        if(i == s.size()){
            ans.push_back(s);
            return;
        }

        if(s[i] >= '0' && s[i] <= '9'){
            helper(i+1, s, ans);
            return;
        }

        helper(i+1, s, ans);
        
        int original = s[i];
        if(islower(s[i])) s[i] = toupper(s[i]);
        else if(isupper(s[i])) s[i] = tolower(s[i]);

        helper(i+1, s, ans);
        s[i] = original;
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(0, s, ans);
        return ans;
    }
};
```