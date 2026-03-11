```cpp
class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>>& adj){
        vector<int> vis(n, 0);

        vis[src] = 1;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == dest)
                return true;
            
            for(int v : adj[u]){
                if(vis[v] == 0){
                    vis[v] == 1;
                    q.push(v);
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return bfs(source, destination, adj);
    }
};
```

## Fastest Solution

```cpp
class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py) parent[px] = py;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i;

        for(auto &e : edges)
            unite(e[0], e[1]);

        return find(source) == find(destination);
    }
};
```

## DFS Based
```cpp
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int src, int dest){

        if(src == dest) return true;

        vis[src] = true;

        for(int v : adj[src]){
            if(!vis[v] && dfs(adj, vis, v, dest))
                return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);

        return dfs(adj,vis,source,destination);
    }
};
```