```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int shifts = 0;
        while(left != right){ // shift until they become equal for example 0...00011 and 0...00011
            left >>= 1;
            right >>= 1;
            shifts++;
        }

        return left << shifts;
    }
};
```