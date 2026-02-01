```cpp
class Solution {
  public:
    bool canAccomodate(int dist, int k, vector<int> &stalls){
        int i = 0, count = 1; // count = 1 because 1 cow will always be there
        for(int j = 1 ; j < stalls.size() ; ++j){
            if(stalls[j] - stalls[i] >= dist){
                count++;
                i = j;
            }
            
            if (count >= k) return true;
        }
        
        return count >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int low = 0, high = stalls[n-1];
        while(low < high){
            int mid = low + (high - low + 1)/2;
            
            if(canAccomodate(mid, k, stalls)) low = mid;
            else high = mid-1;
        }
        
        return low;
    }
};
```