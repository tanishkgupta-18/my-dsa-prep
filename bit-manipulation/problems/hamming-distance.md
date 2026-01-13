## Solution-1

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int bit = 0 ; bit < 32 ; ++bit){
            count += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }

        return count;
    }
};
```

## Solution-2

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;   // bits that differ
        int count = 0;

        while (n) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};
```