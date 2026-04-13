```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while (k > 0) {
            st.pop_back();
            k--;
        }

        string res(st.begin(), st.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};
```