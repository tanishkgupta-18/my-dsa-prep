```cpp
class Solution {
  public:
    int maxDepth(Node *root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh, rh);
    }
};
```

## Iterative BFS
```cpp
class Solution {
  public:
    int maxDepth(Node *root) {
        queue<Node*> q;
        q.push(root);
        
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i < size ; ++i){
                Node* node = q.front(); q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            depth++;
        }
        
        return depth;
    }
};
```