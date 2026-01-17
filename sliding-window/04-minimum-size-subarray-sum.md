```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minLength = INT_MAX;

        int i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];

            while(sum >= target){
                minLength = min(minLength, j-i+1);
                sum-=nums[i++];
            }

            j++;
        }  

        return (minLength == INT_MAX)? 0 : minLength;
    }
};
```