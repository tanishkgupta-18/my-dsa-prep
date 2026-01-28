```cpp
void rangeUpdate(vector<int>& arr, int n, vector<vector<int>>& queries) {
    vector<int> diff(n + 1, 0);

    for (auto& q : queries) {
        int L = q[0], R = q[1], val = q[2];
        diff[L] += val;
        if (R + 1 < n) {
            diff[R + 1] -= val;
        }
    }

    // Convert difference array to actual values
    int currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum += diff[i];
        arr[i] = currentSum;
    }
}
```