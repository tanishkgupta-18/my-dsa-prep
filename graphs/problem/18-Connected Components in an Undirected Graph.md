```cpp
class DisjointSet{
  vector<int> parent, rank;

public:
  DisjointSet(int n){
      parent.resize(n);
      rank.resize(n, 0);
      
      for(int i = 0 ; i < n ; ++i) parent[i] = i;
  }
  
  int find(int node){
      if(node == parent[node]) return node;
      
      return parent[node] = find(parent[node]);
  }
  void unite(int u, int v){
        int ulpU = find(u);
        int ulpV = find(v);
      
        if(ulpU == ulpV) return;
      
        if(rank[ulpU] > rank[ulpV])
            parent[ulpV] = ulpU;
        
        else if(rank[ulpU] < rank[ulpV])
            parent[ulpU] = ulpV;
            
        else{
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
  }
};
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        DisjointSet ds(V);
        
        for (auto& edge : edges) {
            ds.unite(edge[0], edge[1]);
        }
        
        unordered_map<int, vector<int>> componentsMap;
        for (int i = 0; i < V; i++) {
            int root = ds.find(i);
            componentsMap[root].push_back(i);
        }
        
        vector<vector<int>> result;
        for (auto& it : componentsMap) {
            result.push_back(it.second);
        }

        return result;
    }
};
```