```cpp
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq;
    vector<int> res;

    for (int x : nums1)
        freq[x]++;

    for (int x : nums2) {
        if (freq[x] > 0) {
            res.push_back(x);
            freq[x]--;
        }
    }

    return res;
}
```