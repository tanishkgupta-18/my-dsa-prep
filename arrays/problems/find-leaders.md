```cpp
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        int currMax = INT_MIN;
        for(int i = n-1 ; i >= 0 ; --i){
            if(arr[i] >= currMax){
                ans.push_back(arr[i]);
                currMax = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```