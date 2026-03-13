## Solution-1
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findOrder(vector<string> &words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto &w : words){
            for(char c : w){
                adj[c];
                indegree[c] = 0;
            }
        }

        int n = words.size();
        for(int i = 0; i < n-1; i++){

            string s = words[i];
            string t = words[i+1];

            int len = min(s.size(), t.size());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(s[j] != t[j]){

                    if(!adj[s[j]].count(t[j])){
                        adj[s[j]].insert(t[j]);
                        indegree[t[j]]++;
                    }

                    found = true;
                    break;
                }
            }

            // invalid prefix case
            if(!found && s.size() > t.size())
                return "";
        }

        queue<char> q;

        for(auto &it : indegree){
            if(it.second == 0)
                q.push(it.first);
        }

        string ans;

        while(!q.empty()){

            char u = q.front();
            q.pop();

            ans += u;

            for(char v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        // cycle check
        if(ans.size() != adj.size())
            return "";

        return ans;
    }
};
```

## Solution-2
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(char u,
             unordered_map<char, unordered_set<char>>& adj,
             unordered_map<char,int>& vis,
             stack<char>& st)
    {
        vis[u] = 1; // visiting

        for(char v : adj[u]){

            if(vis[v] == 1) 
                return false; // cycle detected

            if(vis[v] == 0){
                if(!dfs(v, adj, vis, st))
                    return false;
            }
        }

        vis[u] = 2; // visited
        st.push(u);
        return true;
    }

    string findOrder(vector<string> &words) {

        unordered_map<char, unordered_set<char>> adj;

        // insert all characters
        for(auto &w : words)
            for(char c : w)
                adj[c];

        int n = words.size();

        // build graph from adjacent words
        for(int i = 0; i < n-1; i++){

            string s = words[i];
            string t = words[i+1];

            int len = min(s.size(), t.size());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(s[j] != t[j]){
                    adj[s[j]].insert(t[j]);
                    found = true;
                    break;
                }
            }

            // prefix edge case
            if(!found && s.size() > t.size())
                return "";
        }

        unordered_map<char,int> vis;
        stack<char> st;

        // topo sort
        for(auto &it : adj){
            if(vis[it.first] == 0){
                if(!dfs(it.first, adj, vis, st))
                    return ""; // cycle
            }
        }

        string ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
```

## Solution-3
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;

        for(auto &w : words)
            for(char c : w)
                indeg[c] = 0;

        for(int i=0;i<words.size()-1;i++){
            string a = words[i], b = words[i+1];
            int len = min(a.size(), b.size());

            for(int j=0;j<len;j++){
                if(a[j]!=b[j]){
                    adj[a[j]].push_back(b[j]);
                    indeg[b[j]]++;
                    break;
                }
            }

            if(a.substr(0,len)==b.substr(0,len) && a.size()>b.size())
                return "";
        }

        queue<char> q;
        for(auto &it:indeg)
            if(it.second==0) q.push(it.first);

        string ans;

        while(!q.empty()){
            char u=q.front(); q.pop();
            ans+=u;

            for(char v:adj[u])
                if(--indeg[v]==0)
                    q.push(v);
        }

        return ans.size()==indeg.size()?ans:"";
    }
};
```