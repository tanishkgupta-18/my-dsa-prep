```cpp
class Solution {
  public:
    vector<int> largestAndSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int firstMax = -1, secondMax = -1;
        for(int i = 0 ; i < n ; ++i){
            if(arr[i] > firstMax){
                secondMax = firstMax;
                firstMax = arr[i];
            } else if (arr[i] > secondMax && arr[i] < firstMax) {
                secondMax = arr[i];
            }
        }
        
        return {firstMax, secondMax};
    }
};
```