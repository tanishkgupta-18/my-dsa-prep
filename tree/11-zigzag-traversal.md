```cpp
class Solution {
public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        
        deque<Node*> dq;
        dq.push_back(root);
        
        vector<int> res;
        
        bool leftToRight = false;
        
        while (!dq.empty()) {
            int size = dq.size();
            
            for (int i = 0; i < size; i++) {
                if (leftToRight) {
                    // Left → Right
                    Node* node = dq.front();
                    dq.pop_front();
                    
                    res.push_back(node->data);
                    
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    // Right → Left
                    Node* node = dq.back();
                    dq.pop_back();
                    
                    res.push_back(node->data);
                    
                    // push children in reverse order
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }
            
            leftToRight = !leftToRight;
        }
        
        return res;
    }
};
```