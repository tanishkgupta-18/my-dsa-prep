```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n;

        while(l < r){
            long long mid = l + (r-l+1)/2;

            long long total = mid*(mid+1)/2;
            
            //[T, T, T, F, F] take the last true
            if(total <= (long long)n) l = mid; ue
            else r = mid-1;
        }

        return (int)l;
    }
};
```