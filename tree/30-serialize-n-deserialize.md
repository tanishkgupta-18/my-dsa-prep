```cpp
class Codec {
public:

    // Serialize using BFS
    string serialize(TreeNode* root) {
        if (!root) return "";

        string result = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                result += "N ";
            } else {
                result += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return result;
    }

    // Deserialize using BFS
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;

        stringstream ss(data);
        string val;

        // Get root
        ss >> val;
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!(ss >> val)) break;
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Right child
            if (!(ss >> val)) break;
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};
```