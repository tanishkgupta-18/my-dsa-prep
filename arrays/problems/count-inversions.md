```cpp
class Solution {
  public:
    int merge(int low, int mid, int high, vector<int>& arr){
        vector<int> temp;
        int i = low, j = mid+1, count = 0;
        while(i <= mid && j <= high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                count += (mid - i + 1);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k = low ; k <= high ; ++k){
            arr[k] = temp[k - low];
        }
        
        return count;
    }
    int mergeSort(int low, int high, vector<int>& arr){
        if(low >= high) return 0;
        
        int invCount = 0;
        int mid = low + (high-low)/2;
        
        invCount += mergeSort(low, mid, arr);
        invCount += mergeSort(mid+1, high, arr);
        invCount += merge(low, mid, high, arr);
        
        return invCount;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        return mergeSort(0, n-1, arr);
    }
};
```