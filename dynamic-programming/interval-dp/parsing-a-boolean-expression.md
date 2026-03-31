```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression){
            if(c == ',' ) continue;

            if(c != ')'){
                st.push(c);
            }else{
                vector<char> v;

                while(st.top() != '('){
                    v.push_back(st.top());
                    st.pop();
                }

                st.pop(); // remove '('

                char op = st.top();
                st.pop();

                bool ans;

                if(op == '&'){
                    ans = true;
                    for(char x : v){
                        if(x == 'f'){
                            ans = false;
                            break;
                        }
                    }
                }
                else if(op == '|'){
                    ans = false;
                    for(char x : v){
                        if(x == 't'){
                            ans = true;
                            break;
                        }
                    }
                }
                else{ // '!'
                    ans = (v[0] == 'f');
                }

                st.push(ans ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};
```