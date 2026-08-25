```cpp
class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {

        int n = a.size();
        int m = b.size();

        // Binary search on the smaller array
        if (n > m)
            return kthElement(b, a, k);

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {

            int x = low + (high - low) / 2;
            int y = k - x;

            int aLeft  = (x == 0) ? INT_MIN : a[x - 1];
            int aRight = (x == n) ? INT_MAX : a[x];

            int bLeft  = (y == 0) ? INT_MIN : b[y - 1];
            int bRight = (y == m) ? INT_MAX : b[y];

            // Correct partition
            if (aLeft <= bRight && bLeft <= aRight) {
                return max(aLeft, bLeft);
            }

            // Took too many from a
            else if (aLeft > bRight) {
                high = x - 1;
            }

            // Took too few from a
            else {
                low = x + 1;
            }
        }

        return -1;
    }
};
```