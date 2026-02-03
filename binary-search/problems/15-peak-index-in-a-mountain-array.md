## Using First True template
```cpp
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left = 0, right = arr.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] >= arr[mid + 1]) { // first time its true it is the peak
				right = mid;
			} else {
				left = mid + 1;
			}
		}

		return left;
	}
};
```

## Standard Approach
```cpp
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		// Peak can't be at index 0 or n-1, so we narrow the search space
		int left = 1, right = arr.size() - 2;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			// 1. Explicit Peak Check (Safe because of left=1, right=n-2)
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				return mid;
			}

			// 2. Decide which side to go
			if (arr[mid] < arr[mid + 1]) {
				// We are on the upward slope, peak is to the right
				left = mid + 1;
			} else {
				// We are on the downward slope, peak is to the left
				right = mid - 1;
			}
		}

		return -1;
	}
};
```