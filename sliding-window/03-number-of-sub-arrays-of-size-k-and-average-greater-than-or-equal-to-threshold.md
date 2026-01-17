```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int target = k * threshold;
        int sum = 0, count = 0;

        // first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum >= target) count++;

        // slide window
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            if (sum >= target) count++;
        }

        return count;
    }
};
```