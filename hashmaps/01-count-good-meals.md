```cpp
/*
    good meals = two different items and sum of their deliciousness = power of two
    
    if we can able to find a food item can create how many power of two with other members

    [1,3,5,7,9]

    1 count is 2
    3 count is 1
    7 count is 1
    rest are 0...

    ans = we just need to add count of each

    so problem simplifies
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> count;

        int ans = 0;
        for(int& d : deliciousness){
            for(int i = 0 ; i <= 22 ; ++i){
                int powerOfTwo = 1 << i; 
                int other = powerOfTwo - d;
                
                if(count.find(other) != count.end())
                    ans = (ans + count[other])%MOD;
            }

            count[d]++;
        }

        return ans;
    }
};
```