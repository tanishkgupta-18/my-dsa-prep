```cpp
class Solution {
public:
    int sum = 0;

    void solve(int i, int n, int xr, vector<int>& nums) {

        if(i == n) {
            sum += xr;
            return;
        }

        // Not take
        solve(i+1, n, xr, nums);

        // Take
        solve(i+1, n, xr ^ nums[i], nums);
    }

    int subsetXORSum(vector<int>& nums) {
        sum = 0;
        int n = nums.size();

        solve(0, n, 0, nums);

        return sum;
    }
};
```