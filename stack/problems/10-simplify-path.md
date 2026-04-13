```cpp
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> st;

        for(int i = 0 ; i < n ; i++){
            if(path[i] == '/') continue;

            string curr = "";
            while(i < n && path[i] != '/'){
                curr += path[i];
                i++;
            }

            if(curr == ".") continue;
            if(curr == ".."){
                if(!st.empty()) st.pop_back();
                continue;
            }

            st.push_back(curr);
        }

        if(st.empty()) return "/";
        string res = "";
        for(int i = 0 ; i < st.size() ; ++i){
            res = res + "/" + st[i];
        }

        return res;
    }
};
```