```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0), ans(n);

        for(auto& b : bookings){
            int l = b[0]-1, r = b[1]-1, val = b[2]; // convert to 0 based indexing
            diff[l] += val;

            if(r+1 < n)
                diff[r+1] -= val;
        }

        int total = 0;
        for(int i = 0 ; i < n ; ++i){
            total += diff[i];
            ans[i] = total;
        }

        return ans;
    }
};
```