```cpp
#include <bits/stdc++.h> 
void expand(int left, int right, string& s, int &start, int &maxLen){
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        int currLen = right - left + 1;

        if(currLen > maxLen){
            maxLen = currLen;
            start = left;
        }

        left--;
        right++;
    }
}

string longestPalinSubstring(string &str){
    int start = 0;
    int maxLen = 1;

    for(int i = 0 ; i < str.length() ; ++i){
        expand(i, i, str, start, maxLen);

        expand(i, i+1, str, start, maxLen);
    }

    return str.substr(start, maxLen);
}
```