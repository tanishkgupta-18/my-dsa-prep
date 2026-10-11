```cpp
int findTarget(vector<int>& arr, int x) {
    int n = arr.size();
    int i = 0;

    while (i < n) {
        if (arr[i] == x)
            return i;

        i += abs(arr[i] - x);
    }

    return -1;
}
```

> follow up |arr[i] - arr[i+1]| = K
```cpp
int findTarget(vector<int>& arr, int x, int k) {
    int n = arr.size();

    // x cannot occur in the array
    if (abs(arr[0] - x) % k != 0)
        return -1;

    int i = 0;

    while (i < n) {
        if (arr[i] == x)
            return i;

        int jump = abs(arr[i] - x) / k;
        i += jump;
    }

    return -1;
}
```