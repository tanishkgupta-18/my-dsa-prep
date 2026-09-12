```cpp
/*
Statement:
    unique integers arr and arr[i] > 1
    construct binary tree and arr[i] can be used any no. of times
    non leaf node value = product of its childrens
    return no. of binary trees we can make

Observations
    binary tree has atmost two children
    so break the numbers in product of two nums and further break it 
    and count all combinations
    [20,10,5,4,2]
    20 = 10x2, 5x4 => (6) + (4) + 1 = 11
    10 = 5x2 => 3
    4 = 2x2 => 2
    5 = 1 way
    2 = 1 way
*/

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<long long, long long> ways;
        unordered_set<long long> nums(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i) {
            ways[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];

                    if (nums.count(right)) {
                        ways[arr[i]] =
                            (ways[arr[i]] +
                             ways[arr[j]] * ways[right]) % MOD;
                    }
                }
            }
        }

        long long total = 0;
        for(auto [nums, value] : ways) total = (total + value) % MOD;

        return total;
    }
};
```