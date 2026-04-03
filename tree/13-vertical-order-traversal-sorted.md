```cpp
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<Node*, int, int>> q;
        vector<vector<int>> res;
        q.push({root, 0, 0});
        
        while(!q.empty()){
            auto [node, row, col] = q.front();
            q.pop();
            
            nodes[col][row].insert(node->data);
            
            if(node->left) q.push({node->left, row+1, col-1});
            if(node->right) q.push({node->right, row+1, col+1});
        }
        
        for(auto& cols : nodes){
            vector<int> colNodes;
            for(auto& rows : cols.second){
                colNodes.insert(colNodes.end(), rows.second.begin(), rows.second.end());
            }
            
            res.push_back(colNodes);
        }
        
        return res;
    }
};
```