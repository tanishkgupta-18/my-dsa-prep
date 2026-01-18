```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int i = 0, ans = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;

            while (freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0)
                    freq.erase(s[i]);
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
```

## Alternate
```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> freq(256, 0);
        int i = 0, distinct = 0, ans = 0;

        for (int j = 0; j < s.size(); j++) {
            if (freq[s[j]] == 0) distinct++;
            freq[s[j]]++;

            while (distinct > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) distinct--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
```