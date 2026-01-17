```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX, ans = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < n-2 ; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - sum);
                
                if(diff < minDiff){
                    minDiff = diff;
                    ans = sum;
                }

                if(sum == target) return sum;
                if(sum > target){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return ans;
    }
};
```