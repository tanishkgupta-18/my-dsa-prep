```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for(int num : nums) xorAll^=num;

        int rightmostBit = xorAll & -xorAll; // gives rightmost bit

        int a = 0, b = 0;
        for(int num : nums){
            // grouping based on rightmost bit set or not
            if(num & rightmostBit) a^=num; 
            else b^=num;
        }

        return {a, b};
    }
};
```