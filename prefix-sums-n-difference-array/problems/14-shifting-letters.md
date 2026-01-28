```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<long long> diff(n+1, 0);

        for(int i = 0 ; i < n ; ++i){
            int l = 0, r = i;

            diff[l] += shifts[i];

            if(r+1 < n)
                diff[r+1] -= shifts[i];
        }

        long long totalShifts = 0;
        for(int i = 0 ; i < n ; ++i){
            totalShifts += diff[i];
            
            int netShift = totalShifts%26;

            s[i] = (s[i] - 'a' + netShift)%26 + 'a';
        }

        return s;
    }
};
```