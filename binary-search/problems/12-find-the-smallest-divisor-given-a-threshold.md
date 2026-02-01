```cpp
class Solution {
public:
    bool check(int div, int threshold, vector<int>& nums){
        long long sum = 0;
        for (int n : nums) {
            sum += (n + div - 1) / div;
        }
        
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1, high = 1e6;
        while(low < high){
            int mid = low + (high - low)/2;

            if(check(mid, threshold, nums)) high = mid;
            else low = mid+1;
        }

        return low; 
    }
};
```