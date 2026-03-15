## Intuitive Solution
```cpp
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {
        int ulpU = find(u);
        int ulpV = find(v);

        if (ulpU == ulpV)
            return;

        if (rank[ulpU] > rank[ulpV])
            parent[ulpV] = ulpU;

        else if (rank[ulpU] < rank[ulpV])
            parent[ulpU] = ulpV;

        else {
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        for(int i = 0 ; i < n ; ++i){
            int x1 = stones[i][0], y1 = stones[i][1];
            for(int j = i+1 ; j < n ; ++j){
                int x2 = stones[j][0], y2 = stones[j][1];

                if(x1 == x2 || y1 == y2)
                    ds.unite(i, j);
            }
        }

        unordered_map<int, vector<int>> components;
        for(int i = 0 ; i < n ; ++i){
            int p = ds.find(i);
            components[p].push_back(i);
        }

        int ans = 0;
        for(auto& [_, v] : components){
            ans += v.size()-1;
        }

        return ans;
    }
};
```

## Optimal Solution (Offset Trick)
```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0, maxCol = 0;

        for (auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + maxRow + 1;

            ds.unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (auto node : nodes) {
            if (ds.find(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};
```