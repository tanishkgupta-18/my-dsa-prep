```cpp
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;

        for(int num : nums) if(num >=0) nonNeg.push_back(num);

        int n = nonNeg.size();

        if(n == 0) return nums;

        k = k%n;

        rotate(nonNeg.begin(), nonNeg.begin()+k, nonNeg.end());

        int j = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] >= 0){
                nums[i] = nonNeg[j++];
            }
        }

        return nums;
    }
};
```