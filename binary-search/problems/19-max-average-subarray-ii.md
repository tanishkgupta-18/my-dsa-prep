```cpp
class Solution {
public:
bool check(double mid, const vector<int>& nums, int k) {
        int n = nums.size();
        
        double currentSum = 0;
        for(int i = 0; i < k; ++i) {
            currentSum += (nums[i] - mid);
        }

        if(currentSum >= 0) return true;

        double prevSum = 0;
        double minPrevSum = 0;

        for(int i = k; i < n; ++i) {
            currentSum += (nums[i] - mid);
            prevSum += (nums[i - k] - mid);
            
            minPrevSum = min(minPrevSum, prevSum);

            if(currentSum - minPrevSum >= 0) return true;
        }

        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double low = -1e4;
        double high = 1e4;

        for(int i = 0 ; i < 100 ; ++i){
            double mid = low + (high - low) / 2.0;

            if(check(mid, nums, k)){
                low = mid;
            }else{
                high = mid;
            }
        }

        return low; 
    }
};
```