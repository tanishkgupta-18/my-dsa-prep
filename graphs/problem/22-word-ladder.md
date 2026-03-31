## Approach 1
```cpp
class Solution {
public:
    bool isMatch(string& s, string& t){
        int j = 0, notMatch = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] != t[j]) notMatch++;
            j++;
        }

        return notMatch == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        unordered_set<string> vis;
        vis.insert(beginWord);
        
        while(!q.empty()){
            auto [steps, word] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0 ; i < wordList.size() ; ++i){
                if(isMatch(word, wordList[i]) && !vis.count(wordList[i])){
                    q.push({steps+1, wordList[i]});
                    vis.insert(wordList[i]);
                }
            }
        }

        return 0;
    }
};
```

## Approach 2
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // Important edge case
        if (!st.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            // Try all possible transformations
            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.count(temp)) {
                        q.push({temp, steps + 1});
                        st.erase(temp); // mark visited
                    }
                }
            }
        }

        return 0;
    }
};
```

## Approach 3
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};

        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {

            // Always expand smaller set
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextLevel;

            for (auto word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[i] = ch;

                        // If found in opposite set → path found
                        if (endSet.count(temp)) {
                            return steps + 1;
                        }

                        if (st.count(temp)) {
                            nextLevel.insert(temp);
                            st.erase(temp); // mark visited
                        }
                    }
                }
            }

            beginSet = nextLevel;
            steps++;
        }

        return 0;
    }
};
```