```cpp
/*
    The property being counted is integer-valued and monotonic with respect to window expansion/shrinking.
    subarrays with sum == goal = subarrays with sum ≤ goal − subarrays with sum ≤ goal − 1
*/

/*NOTE: Works only for non-negative integers if negatives are allowed then we go for universal solution*/
class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int i = 0, sum = 0, res = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i++];
            }
            res += (j - i + 1);
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};
```

## Universal Solution Works All Time if array is additive
```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0, count = 0;

        for (int x : nums) {
            sum += x;
            if (freq.count(sum - goal)) {
                count += freq[sum - goal];
            }
            freq[sum]++;
        }

        return count;
    }
};
```