```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, freq;
        for (char c : t) need[c]++;

        int l = 0, minLen = INT_MAX, start = 0;
        int matches = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            freq[c]++;

            if (need.count(c) && freq[c] == need[c]) {
                matches++;
            }

            while (matches == need.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                freq[leftChar]--;

                if (need.count(leftChar) && freq[leftChar] < need[leftChar]) {
                    matches--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
```

## Optimised Solution
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int required = t.size();   // total chars needed
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            if (mp[c] > 0) required--;
            mp[c]--;

            while (required == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                mp[leftChar]++;

                if (mp[leftChar] > 0) required++;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
```