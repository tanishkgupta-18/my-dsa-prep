```cpp
class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, vector<int>> nodes;
        vector<int> res;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto[node, col] = q.front();
            q.pop();
            nodes[col].push_back(node->data);
            
            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
        }
        
        
        for(auto cols : nodes){
            res.push_back(cols.second[0]);
        }
        
        return res;
    }
};
```

## Optimised
```cpp
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> mp; // col -> first node
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            // first node at this column
            if (mp.find(col) == mp.end()) {
                mp[col] = node->data;
            }

            if (node->left)
                q.push({node->left, col - 1});

            if (node->right)
                q.push({node->right, col + 1});
        }

        for (auto& it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
```