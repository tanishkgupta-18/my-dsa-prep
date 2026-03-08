```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0 ; i < n ; ++i){
            for(int j = i+1 ; j < n ; ++j){
                int product = nums[i] * nums[j];
                freq[product]++;
            }
        }

        int ans = 0;
        for(auto& [prod, k] : freq){
            if(k > 1){
                ans += k * (k - 1) * 4;  // C(k,2) * 8
            }
        }

        return ans;
    }
};
```

## Improved Version
```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int p = nums[i] * nums[j];

                ans += freq[p] * 8;  // existing pairs with same product
                freq[p]++;
            }
        }

        return ans;
    }
};
```