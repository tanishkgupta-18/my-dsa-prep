```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st;
        for(auto& b : bank)
            st.insert(b);

        queue<pair<int, string>> q;
        q.push({0, startGene});

        unordered_set<string> vis;
        vis.insert(startGene);

        string t = "ACGT";
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int step = p.first;
            string s = p.second;

            if(s == endGene) return step;

            for(int i = 0 ; i < startGene.size() ; ++i){
                string mutated = s;
                for(int j = 0 ; j < t.size() ; ++j){
                    if(mutated[i] == t[j]) continue;

                    mutated[i] = t[j];
                    if(!vis.count(mutated) && st.find(mutated) != st.end()){
                        vis.insert(mutated);
                        q.push({step+1, mutated});
                    }
                }
            }
        }

        return -1;
    }
};
```