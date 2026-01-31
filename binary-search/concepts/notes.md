# Binary Search: Lower Bound & Upper Bound

### 1. The Definitions

| Function | Condition | Description |
| --- | --- | --- |
| **Lower Bound** | `arr[i] >= target` | Smallest index `i` such that value is at least target. |
| **Upper Bound** | `arr[i] > target` | Smallest index `i` such that value is strictly greater than target. |

### 2. C++ STL Usage

```cpp
#include <algorithm>

// Returns an iterator
auto lb = std::lower_bound(v.begin(), v.end(), target);
auto ub = std::upper_bound(v.begin(), v.end(), target);

// Convert to index
int lb_idx = lb - v.begin();
int ub_idx = ub - v.begin();

// Edge Case: If target > max(array), lb and ub will return v.end()

```

### 3. Manual Implementation Templates

Use these to avoid infinite loops and handle boundaries correctly.

#### Lower Bound ( Target)

```cpp
int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = nums.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans = mid;      // Possible answer
            high = mid - 1; // Try to find a smaller index
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

```

#### Upper Bound ( Target)

```cpp
int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = nums.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            ans = mid;      // Possible answer
            high = mid - 1; // Look left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

```

### 4. Interview Cheat Sheet

* **Check if element exists:** `lb != v.end() && *lb == target`
* **First Occurrence:** `lower_bound` index.
* **Last Occurrence:** `upper_bound` index - 1.
* **Count of Element:** `upper_bound - lower_bound`.
* **Number of elements < X:** `lower_bound` index.
* **Number of elements <= X:** `upper_bound` index.

**Complexity:**

* **Time:** $O(\log N)$
* **Space:** $O(1)$

---
