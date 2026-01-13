```cpp
class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int bit = 0 ; bit < 32 ; ++bit){
            res = res << 1 | (n & 1);
            n >>= 1;
        }

        return res;
    }
};
```