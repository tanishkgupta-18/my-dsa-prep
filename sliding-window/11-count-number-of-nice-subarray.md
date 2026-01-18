```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int cnt = 0, res = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            cnt += (nums[i]&1)? 1 : 0;

            if(freq.count(cnt - k)) res += freq[cnt - k];

            freq[cnt]++;
        }

        return res;
    }
};
```

## Alternate
```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int i = 0, oddCount = 0, res = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] & 1) oddCount++;

            while (oddCount > k) {
                if (nums[i] & 1) oddCount--;
                i++;
            }

            res += (j - i + 1);
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
```