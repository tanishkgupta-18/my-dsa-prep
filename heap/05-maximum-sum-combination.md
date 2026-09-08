```cpp

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        
        vector<int> result;
        
        priority_queue<pair<int, pair<int, int>>> max_heap;
        set<pair<int, int>> visited;
        
        max_heap.push({A[0] + B[0],{0, 0}});
        visited.insert({0, 0});
        
        while(K-- && !max_heap.empty()){
            auto value = max_heap.top();
            max_heap.pop();
            
            int sum = value.first;
            int i = value.second.first;
            int j = value.second.second;
            
            result.push_back(sum);
            
            if(i+1 < N && !visited.count({i+1, j})){
                max_heap.push({A[i+1] + B[j], {i+1, j}});
                visited.insert({i+1, j});
            }
            
            if(j+1 < N && !visited.count({i, j+1})){
                max_heap.push({A[i] + B[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }
        
        return result;
    }
};
```