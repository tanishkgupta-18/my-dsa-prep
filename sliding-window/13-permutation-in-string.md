```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if (k > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for (int i = 0; i < k; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2) return true;

        for (int i = k; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;          // add new char
            freq2[s2[i - k] - 'a']--;      // remove old char

            if (freq1 == freq2) return true;
        }

        return false;
    }
};
```

## Optimised Solution

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if (k > s2.size()) return false;

        vector<int> freq(26, 0);

        for (char c : s1) {
            freq[c - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) matches++;
        }
        
        for (int i = 0; i < k; i++) {
            int idx = s2[i] - 'a';
            freq[idx]--;
            if (freq[idx] == 0) matches++;
            else if (freq[idx] == -1) matches--; 
        }

        if (matches == 26) return true;

        for (int i = k; i < s2.size(); i++) {
            int add = s2[i] - 'a';
            int rem = s2[i - k] - 'a';

            // add new char
            freq[add]--;
            if (freq[add] == 0) matches++;
            else if (freq[add] == -1) matches--;

            // remove old char
            freq[rem]++;
            if (freq[rem] == 0) matches++;
            else if (freq[rem] == 1) matches--;

            if (matches == 26) return true;
        }

        return false;
    }
};
```