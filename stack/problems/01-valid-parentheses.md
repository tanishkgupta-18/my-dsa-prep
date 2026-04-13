```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        stack<char> st;
        unordered_map<int, int> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char& c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return false;

                char top = st.top();
                if (top != mp[c]) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
```