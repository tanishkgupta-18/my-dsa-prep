```cpp
class Solution {
public:
    
    void bfs(int src, vector<vector<int>>& isConnected, vector<int>& vis){
        int n = isConnected.size();

        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v = 0; v < n; v++){
                if(isConnected[u][v] == 1 && !vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> vis(n,0);

        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bfs(i, isConnected, vis);
                provinces++;
            }
        }

        return provinces;
    }
};
```