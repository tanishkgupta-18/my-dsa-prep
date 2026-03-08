```cpp
class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;

        int curr = 1, cnt = 1;
        while(curr <= n){
            cnt++;
            curr = (curr << 1) | 1; // form 1, 11, 111 ...
        }

        return cnt;
    }
};
```