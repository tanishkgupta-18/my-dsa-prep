```cpp
class Solution {
public:
    int findRank(int value, const vector<vector<int>>& matrix){
        int count = 0;
        for(const auto &row : matrix){
            count += (upper_bound(row.begin(), row.end(), value) - row.begin());
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), low = matrix[0][0], high = matrix[n-1][n-1], ans = low;
        
        while(low <= high){
            int mid = low + (high-low)/2;

            
            if (findRank(mid, matrix) >= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            } 
        }

        return ans;
    }
};
```