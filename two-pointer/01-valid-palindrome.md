```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        
        for(char c : s) {
            if(isalnum(c)) {
                clean += tolower(c);
            }
        }
        
        int l = 0, r = clean.size() - 1;
        while(l < r) {
            if(clean[l] != clean[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
```