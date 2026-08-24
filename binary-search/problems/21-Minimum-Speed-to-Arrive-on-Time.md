```cpp
class Solution {
public:
    bool check(int speed, vector<int>& dist, double hour){
        int n = dist.size();
        double total = 0;
        for(int i = 0 ; i+1 < n ; ++i){
            double curr = ceil(dist[i]/(double)speed);
            total += curr;
        }

        total += (dist[n-1]/(double)speed);

        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e9;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(check(mid, dist, hour)) high = mid;
            else low = mid+1;
        }

        return low == 1e9 ? -1 : low;
    }
};
```