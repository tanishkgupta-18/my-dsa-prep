```cpp
#include <bits/stdc++.h>
using namespace std;

long long getTrappedWater(long long* arr, int n) {

    vector<long long> leftMax(n);
    vector<long long> rightMax(n);

    // Build left max array
    leftMax[0] = arr[0];

    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    // Build right max array
    rightMax[n - 1] = arr[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    // Calculate trapped water
    long long water = 0;

    for(int i = 0; i < n; i++) {

        long long level = min(leftMax[i], rightMax[i]);

        water += level - arr[i];
    }

    return water;
}
```


```cpp
#include <bits/stdc++.h>
using namespace std;

long long getTrappedWater(long long* arr, int n) {

    int left = 0;
    int right = n - 1;

    long long leftMax = 0;
    long long rightMax = 0;

    long long water = 0;

    while(left <= right) {

        // Process smaller side
        if(arr[left] <= arr[right]) {

            if(arr[left] >= leftMax) {
                leftMax = arr[left];
            }
            else {
                water += leftMax - arr[left];
            }

            left++;
        }
        else {

            if(arr[right] >= rightMax) {
                rightMax = arr[right];
            }
            else {
                water += rightMax - arr[right];
            }

            right--;
        }
    }

    return water;
}
```