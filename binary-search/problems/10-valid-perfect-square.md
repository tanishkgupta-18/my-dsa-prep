```cpp
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;

        while(l < r){
            long long mid = l + (r-l+1)/2;

            if(mid*mid <= (long long)x) l = mid;
            else r = mid-1;
        }

        return (int)l;
    }
};
```