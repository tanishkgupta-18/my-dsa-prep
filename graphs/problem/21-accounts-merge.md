```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;

    // Find with path compression
    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union
    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // Step 1: Initialize parent + emailToName
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                parent[acc[i]] = acc[i];
                emailToName[acc[i]] = name;
            }
        }

        // Step 2: Union emails in same account
        for (auto& acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                unite(acc[1], acc[i]); // connect all with first email
            }
        }

        // Step 3: Group emails by root
        unordered_map<string, vector<string>> groups;
        for (auto& p : parent) {
            string root = find(p.first);
            groups[root].push_back(p.first);
        }

        // Step 4: Build result
        vector<vector<string>> result;

        for (auto& g : groups) {
            vector<string>& emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(emailToName[g.first]); // name
            temp.insert(temp.end(), emails.begin(), emails.end());

            result.push_back(temp);
        }

        return result;
    }
};
```


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, string> emailToName;
    unordered_set<string> visited;

    void dfs(string email, vector<string>& comp) {
        visited.insert(email);
        comp.push_back(email);

        for (auto& nei : graph[email]) {
            if (!visited.count(nei)) {
                dfs(nei, comp);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // Step 1: Build graph
        for (auto& acc : accounts) {
            string name = acc[0];

            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;

                if (i == 1) continue;

                // connect acc[1] <-> acc[i]
                graph[acc[1]].push_back(acc[i]);
                graph[acc[i]].push_back(acc[1]);
            }
        }

        // Step 2: DFS to find components
        vector<vector<string>> result;

        for (auto& [email, _] : emailToName) {
            if (!visited.count(email)) {
                vector<string> comp;
                dfs(email, comp);

                sort(comp.begin(), comp.end());

                vector<string> temp;
                temp.push_back(emailToName[email]); // name
                temp.insert(temp.end(), comp.begin(), comp.end());

                result.push_back(temp);
            }
        }

        return result;
    }
};
```