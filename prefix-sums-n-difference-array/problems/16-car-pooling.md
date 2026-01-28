```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        // since 0 <= fromi < toi <= 1000
        vector<int> diff(1001, 0);

        for(auto &t : trips){
            int num = t[0], from = t[1], to = t[2];

            diff[from] += num;
            
            diff[to] -= num;
        }

        int current = 0;
        for(int i = 0 ; i <= 1000 ; ++i){
            current += diff[i];

            if(current > capacity) return false;
        }

        return true;
    }
};
```