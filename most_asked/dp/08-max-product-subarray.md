```cpp
int maximumProduct(vector<int> &arr, int n)
{
    vector<int> dpMax(n);
    vector<int> dpMin(n);

    dpMax[0] = arr[0];
    dpMin[0] = arr[0];

    int ans = arr[0];

    for(int i = 1; i < n; i++)
    {
        dpMax[i] = max({
            arr[i],
            arr[i] * dpMax[i-1],
            arr[i] * dpMin[i-1]
        });

        dpMin[i] = min({
            arr[i],
            arr[i] * dpMax[i-1],
            arr[i] * dpMin[i-1]
        });

        ans = max(ans, dpMax[i]);
    }

    return ans;
}
```

> Space Optimisation
```cpp
#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n){
    int currMax = arr[0];
    int currMin = arr[0];
    int ans = arr[0];

    for(int i = 1 ; i < n ; ++i){
        int tempMin = min({arr[i], currMin*arr[i], currMax*arr[i]});
        int tempMax = max({arr[i], currMin*arr[i], currMax*arr[i]});
        
        currMin = tempMin;
        currMax = tempMax;

        ans = max(ans, currMax);
    }

    return ans;
}
```