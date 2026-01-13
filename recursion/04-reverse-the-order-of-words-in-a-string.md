## Recursive Approach
```cpp
#include <bits/stdc++.h>
using namespace std;

void helper(int i, string& s){
    int n = s.length();
    if(i >= n) return;
    
    int j = i;
    while(j < n && s[j] != ' ') j++;
    
    reverse(s.begin()+i, s.begin()+j);
    
    i = j+1;
    helper(i, s);
}

void reverseOrderWords(string& s) {
    reverse(s.begin(), s.end());

    helper(0, s);
}

int main() {
    string s = "when all else fails reboot";
    
    reverseOrderWords(s);
    
    cout << s << '\n'; 
    
    return 0;
}
```

## Iterative Approach
```cpp
string reverseOrderWords(string str) {
    reverse(str.begin(), str.end());

    int n = str.length();
    for(int i = 0 ; i < n ; ){
        int j = i;
        while(j < n && str[j] != ' ') j++;

        reverse(str.begin()+i, str.begin()+j);

        i = j+1;
    }

    return str;
}
```