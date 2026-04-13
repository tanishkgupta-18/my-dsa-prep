```cpp
class Solution {
public:
    string create(string& s){
        string a = "";
        for(char& c : s){
            if(c == '#'){
                if(!a.empty()) a.pop_back();
                else continue;
            } else 
                a.push_back(c);
        }

        return a;
    }
    bool backspaceCompare(string s, string t) {
        return create(s) == create(t);
    }
};
```