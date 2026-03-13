```cpp
class Solution {
public:
    void topoSort(int u, vector<vector<int>>& adj, stack<int>& st, vector<int>& vis){
        vis[u] = 1;

        for(auto& v : adj[u]){
            if(!vis[v]){
                topoSort(v, adj, st, vis);
            }
        }

        st.push(u);
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);

        for(auto& rel : relations){
            int u = rel[0]-1, v = rel[1]-1;
            adj[u].push_back(v);
        }

        stack<int> st;
        vector<int> vis(n, 0);

        for(int u = 0 ; u < n ; ++u)
            if(!vis[u])
                topoSort(u, adj, st, vis);

        vector<int> dp(n, 0);
        for(int i = 0 ; i < n ; ++i) dp[i] = time[i];

        while(!st.empty()){
            int u = st.top();
            st.pop();

            for(int v : adj[u]){
                dp[v] = max(dp[v], dp[u] + time[v]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```