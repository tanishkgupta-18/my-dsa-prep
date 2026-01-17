## 1
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m) return false;

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
            }

            j++;
        }

        return i == n;
    }
};
```
## 2

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (i < s.size() && s[i] == c) {
                i++;
            }
        }
        return i == s.size();
    }
};
```