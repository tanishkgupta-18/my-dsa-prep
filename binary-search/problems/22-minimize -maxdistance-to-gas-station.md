```cpp
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(double max_dist, vector<int>& stations, int k) {
        int count = 0;
        for (size_t i = 0; i < stations.size() - 1; ++i) {
            double gap = stations[i + 1] - stations[i];
            count += static_cast<int>(gap / max_dist);
        }
        return count <= k;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        double l = 0.0;
        double r = stations.back() - stations.front();
        
        for (int iter = 0; iter < 100; ++iter) {
            double mid = l + (r - l) / 2.0;
            
            if (check(mid, stations, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return l;
    }
};
```