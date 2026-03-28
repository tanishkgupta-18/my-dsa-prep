```cpp
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        // Step 1: count frequency difference
        for (int x : nums1) freq[x]++;
        for (int x : nums2) freq[x]--;

        int swaps = 0;

        // Step 2: validate and count mismatches
        for (auto& [num, f] : freq) {
            // if total frequency is odd → impossible
            if (f % 2 != 0) return -1;

            // count extra elements in nums1
            if (f > 0) swaps += f;
        }

        // Step 3: each swap fixes 2 elements
        return swaps / 2;
    }
};
```