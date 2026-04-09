```cpp
class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    // Check if all prefixes exist
    bool checkAllPrefix(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return false;
            
            node = node->get(ch);
            
            if(!node->isEnd()) return false;  
        }
        return true;
    }
};

string completeString(vector<string> &a){
    Trie trie;
    
    // Step 1: insert all words
    for(auto &word : a) {
        trie.insert(word);
    }

    string longest = "";

    // Step 2: check each word
    for(auto &word : a) {
        if(trie.checkAllPrefix(word)) {
            
            if(word.length() > longest.length()) {
                longest = word;
            }
            else if(word.length() == longest.length() && word < longest) {
                longest = word;
            }
        }
    }

    return longest == "" ? "None" : longest;
}
```