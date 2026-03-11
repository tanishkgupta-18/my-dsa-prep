```cpp
class Solution {
public:
    void dfs(int src, vector<bool>& vis, vector<vector<int>>& rooms){
        vis[src] = true;

        for(int nei : rooms[src]){
            if(!vis[nei])
                dfs(nei, vis, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool> vis(n,false);

        dfs(0,vis,rooms);

        for(bool v : vis){
            if(!v) return false;
        }

        return true;
    }
};
```