```cpp
class Solution {
public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
        if (a1.empty()) return;

        map<int, int> freq;
        for(const int x : a1) {
            freq[x]++;
        }
        
        int j = 0;
        for(const int x : a2) {
            if(freq.count(x)) {
                int count = freq[x];
                while(count--) {
                    a1[j++] = x;
                }
                freq.erase(x);
            }
        }
        
        for(auto const& [key, value] : freq) {
            int count = value;
            while(count--) {
                a1[j++] = key;
            }
        }
    }
};
```