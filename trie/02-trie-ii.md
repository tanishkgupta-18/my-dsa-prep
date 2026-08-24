```cpp
class Node {
public:
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

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

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreaseEnd() {
        cntEndWith--;
    }

    void decreasePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
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
            node->increasePrefix();  // prefix count
        }
        node->increaseEnd();  // end count
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getPrefix();
    }
};
```