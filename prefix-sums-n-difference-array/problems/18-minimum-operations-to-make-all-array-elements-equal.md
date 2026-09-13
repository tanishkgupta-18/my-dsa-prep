```cpp
/*
Statement:
nums positive integers
queries size m for ith query make all elements of nums equals to queries[i]

operation to perform:
    increase or decrease element by 1

return array ans of size m ans[i] = min operations required

Observation:
    if we make a graph of y axis if we point the q and create a line parallel to x axis so we can see nums greater than q and less than q
    but problem is that N*M solution can take TLE
    Therefore we need a mechanism or a data structure which gives net operations in O(1) or O(logn) so overall time complexity is O(M).
*/


class Solution {
public:
    using ll = long long;
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int m = queries.size(), n = nums.size();

        sort(nums.begin(), nums.end());

        vector<ll> pref(n+1, 0);
        for(int i = 0 ; i < n ; ++i){
            pref[i+1] = pref[i] + (ll)nums[i];
        }

        vector<ll> answer(m, 0);
        for(int i = 0 ; i < m ; ++i){
            int q = queries[i];

            int left = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
        
            int right = n - left;

            answer[i] = 1LL*q*(left-right) + (pref[n] - 2*pref[left]);
        }

        return answer;
    }
};
```