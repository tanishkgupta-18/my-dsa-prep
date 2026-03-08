```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> first;  // prefix -> first index
        int pref = 0, ans = 0;

        for (int i = 0; i < hours.size(); ++i) {
            pref += (hours[i] > 8) ? 1 : -1;

            if (pref > 0) {
                ans = i + 1;
            } 
            else {
                if (!first.count(pref))
                    first[pref] = i;

                if (first.count(pref - 1)) {
                    ans = max(ans, i - first[pref - 1]);
                }
            }
        }

        return ans;
    }
};
```