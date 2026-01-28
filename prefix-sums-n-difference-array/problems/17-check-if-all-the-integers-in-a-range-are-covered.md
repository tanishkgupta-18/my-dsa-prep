```cpp
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(51, 0);

        for(auto &rg : ranges){
            int l = rg[0], r = rg[1];

            diff[l]++;

            if(r+1 < 51) diff[r+1]--;
        }

        vector<int> freq(51, 0);
        int current = 0;
        for(int i = 0 ; i < 51 ; ++i){
            current += diff[i];
            freq[i] = current;
        }

        for(int i = left ; i <= right ; ++i)
            if(freq[i] == 0) return false;

        return true;
    }
};
```

## $Optimized$
```cpp
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int diff[52] = {0};

        for(auto &rg : ranges) {
            diff[rg[0]]++;
            if(rg[1] + 1 < 52) diff[rg[1] + 1]--;
        }

        int currentFreq = 0;
        for(int i = 1; i <= 50; ++i) {
            currentFreq += diff[i];
            if(i >= left && i <= right && currentFreq <= 0)
                return false;
        }

        return true;
    }
};
```