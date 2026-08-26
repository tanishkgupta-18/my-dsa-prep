```cpp
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = mat[0][0];
        int high = mat[0][m-1];
        
        for(int i = 1 ; i < n ; ++i){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int required = (n*m+1)/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int count = 0;
            for(int i = 0 ; i < n ; ++i){
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(count >= required) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
};
```