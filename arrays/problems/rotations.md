```cpp
void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    
    // Step 1: Reverse whole array
    reverse(nums.begin(), nums.end());
    // Step 2: Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Step 3: Reverse the rest
    reverse(nums.begin() + k, nums.end());
}

void rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    
    // Step 1: Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Step 2: Reverse the rest
    reverse(nums.begin() + k, nums.end());
    // Step 3: Reverse whole array
    reverse(nums.begin(), nums.end());
}
```