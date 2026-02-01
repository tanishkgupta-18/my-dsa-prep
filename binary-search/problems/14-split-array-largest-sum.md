```cpp
class Solution {
public:
	bool check(long long target, int k, vector<int>& nums) {
		long long sum = 0;
		int cnt = 1;
		for (int n : nums) {
			if (sum + n > target) {
				sum = n;
				cnt++;
			} else {
				sum += n;
			}
		}
		return cnt <= k;
	}

	int splitArray(vector<int>& nums, int k) {
		long long high = 0, low = 0;
		for (int n : nums) {
			high += n;
			low = max(low, (long long)n);
		}

		while (low < high) {
			long long mid = low + (high - low) / 2;
			if (check(mid, k, nums))
				high = mid;
			else
				low = mid + 1;
		}
		return (int)low;
	}
};
```