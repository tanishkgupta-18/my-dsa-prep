```
First, we count the frequency of each plank height using a hash map.

The max width for any target height H is the sum of:

The number of single planks of height H.
The number of pairs (a, b) where a + b = H.
2.1 If a != b, each pair (a, b) can form min(count[a], count[b]) planks.
2.2 If a == b, we can form count[a] / 2 planks of height H.
We iterate through all unique plank heights
to calculate the total for every possible combination,
and return the maximum value found.
```

```cpp
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq, res;

        for (int x : planks) {
            freq[x]++;
            res[x]++;
        }

        for (auto const& pair_a : freq) {
            for (auto const& pair_b : freq) {

                int a = pair_a.first;
                int b = pair_b.first;

                if (a < b) {
                    res[a + b] += min(freq[a], freq[b]);
                }

                if (a == b) {
                    res[a + b] += freq[a] / 2;
                }
            }
        }

        int width = 0;

        for (auto const& pair : res) {
            width = max(width, pair.second);
        }

        return width;
    }
};
```