```cpp
class Solution {
public:
    void helper(int i, vector<char>& s){
        int n = s.size();

        if(i == n/2) return;

        swap(s[i], s[n-i-1]);

        helper(i+1, s);
    }

    void reverseString(vector<char>& s) {
        helper(0, s);
    }
};
```