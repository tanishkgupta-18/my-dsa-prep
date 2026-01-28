```cpp
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    // 1. Create a difference array of size length + 1
    vector<int> diff(length + 1, 0);

    // 2. Process all updates in O(1) each
    for (const auto& update : updates) {
        int start = update[0];
        int end = update[1];
        int inc = update[2];

        diff[start] += inc;
        if (end + 1 < length) {
            diff[end + 1] -= inc;
        }
    }

    // 3. Compute the prefix sum to get the final result
    // We can reuse the diff array or create a new one
    vector<int> result(length);
    int currentSum = 0;
    for (int i = 0; i < length; i++) {
        currentSum += diff[i];
        result[i] = currentSum;
    }

    return result;
}
```