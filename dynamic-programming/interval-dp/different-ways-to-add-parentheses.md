```cpp
class Solution {
public:
    vector<int> solve(int i, int j, string& s){
        vector<int> res;

        for(int k = i+1 ; k <= j-1 ; ++k){
            char op = s[k];
            if(op != '+' && op != '-' && op != '*') continue;

            vector<int> left = solve(i, k-1, s);
            vector<int> right = solve(k+1, j, s);

            for(int x : left){
                for(int y : right){
                    if(op == '+'){
                        res.push_back(x+y);
                    }else if(op == '-'){
                        res.push_back(x-y);
                    }else{
                        res.push_back(x*y);
                    }
                }
            }
        }

        if(res.empty()){
            int num = 0;
            for(int k = i ; k <= j ; ++k){
                num = num*10 + (s[k]-'0');
            }

            res.push_back(num);
        }

        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        return solve(0, n-1, expression);
    }
};
```