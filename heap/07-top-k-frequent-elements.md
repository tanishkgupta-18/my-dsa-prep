```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});
        }

        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
```

## Optimal
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};
```