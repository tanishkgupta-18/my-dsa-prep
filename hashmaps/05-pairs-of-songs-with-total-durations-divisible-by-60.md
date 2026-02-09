```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        int ans = 0;

        for (int t : time) {
            int r = t % 60;
            int need = (60 - r) % 60;

            ans += cnt[need];
            cnt[r]++;
        }

        return ans;
    }
};
```