```cpp
#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>& arr) {

    int currentSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1; i < arr.size(); i++) {

        // Either extend previous subarray
        // or start new from current element
        currentSum = max(arr[i], currentSum + arr[i]);

        // Update global maximum
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
```