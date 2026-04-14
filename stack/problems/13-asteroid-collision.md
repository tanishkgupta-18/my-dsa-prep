```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int curr : asteroids) {

            while (!st.empty() && st.back() > 0 && curr < 0 && st.back() < abs(curr)) {
                st.pop_back();
            }

            if (!st.empty() && st.back() > 0 && curr < 0 && st.back() == abs(curr)) {
                st.pop_back();
                continue;
            }

            if (!st.empty() && st.back() > 0 && curr < 0 && st.back() > abs(curr)) {
                continue;
            }

            st.push_back(curr);
        }

        return st;
    }
};
```