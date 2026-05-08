```cpp
long long maxSubarraySum(vector<int> arr, int n){
    long long maxSum = 0;
    long long currentSum = 0;

    for(int i = 0 ; i < arr.size() ; ++i){
        currentSum += arr[i];

        maxSum = max(maxSum, currentSum);

        if(currentSum < 0) currentSum = 0;
    }

    return maxSum;
}
```