```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        // NSE (next smaller or equal)
        for(int i = n-1 ; i >= 0 ; --i){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(!st.empty()) nse[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // PSE (previous smaller)
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(!st.empty()) pse[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        for(int i = 0 ; i < n ; ++i){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans = (ans + (left * right % mod) * arr[i] % mod) % mod;
        }

        return ans;
    }
};
```