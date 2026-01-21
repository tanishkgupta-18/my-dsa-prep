```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        if(k > s.size()) return {};

        vector<int> freq(26, 0), ans;
    
        for(auto c : p) freq[c-'a']++;

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) matches++;
        }

        
        for(int i = 0 ; i < k ; ++i){
            int idx = s[i]-'a';

            freq[idx]--;
            if(freq[idx] == 0) matches++;
            else if(freq[idx] == -1) matches--; 
        }

        if(matches == 26) ans.push_back(0);

        for(int i = k ; i < s.size() ; ++i){
            int add = s[i] - 'a';
            int rem = s[i-k] - 'a';

            freq[add]--;
            if(freq[add] == 0) matches++;
            else if(freq[add] == -1) matches--;

            freq[rem]++;
            if(freq[rem] == 0) matches++;
            else if(freq[rem] == 1) matches--;

            if(matches == 26) ans.push_back(i-k+1);
        }

        return ans;
    }
};
```