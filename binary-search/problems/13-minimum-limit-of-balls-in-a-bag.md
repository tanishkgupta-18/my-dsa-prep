```cpp
class Solution {
public:
    bool check(int penalty, int maxOperations, vector<int>& nums){
        long long count = 0;
        for(int num : nums){
            int val = num / penalty;
            if(num % penalty == 0) val--;
            count = count + val;

            if(count > maxOperations) return false;
        }
            
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = 1e9;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(check(mid, maxOperations, nums)) 
                high = mid;
            else
                low = mid+1;
        }

        return low;
    }
};
```