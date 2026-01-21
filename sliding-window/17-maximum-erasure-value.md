```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int i = 0;
        long long sum = 0, maxSum = 0;

        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            sum += nums[j];

            while (freq[nums[j]] > 1) {
                freq[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
```