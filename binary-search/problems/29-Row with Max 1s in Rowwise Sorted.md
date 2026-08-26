```cpp
class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int ans = -1;
        int maxOnes = 0;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[i][mid] == 1)
                    high = mid - 1;   // search for first 1
                else
                    low = mid + 1;
            }

            // low = index of first 1
            int ones = m - low;

            if (ones > maxOnes) {
                maxOnes = ones;
                ans = i;
            }
        }

        return ans;
    }
};
```