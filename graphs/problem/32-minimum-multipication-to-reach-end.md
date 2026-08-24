```cpp
/*
Given:
    start and end are given.
    In one operation, we can multiply the current value by any number from arr.

    newValue = (current * arr[i]) % 1000

    Find the minimum number of operations required to reach end from start.
    If it is not possible, return -1.

Approach:
    Since every operation has equal cost (1 step),
    we can model this as an unweighted graph and use BFS.

    Define a queue storing pairs:
        (currentValue, steps)

    Define a distance/visited array of size 1000
    because after modulo operation all possible states are 0 to 999.

    Push:
        (start, 0)

    Mark:
        dist[start] = 0

    While queue is not empty:

        [node, steps] = q.front()
        q.pop()

        If node == end:
            return steps

        For each x in arr:

            newValue = (node * x) % 1000

            If steps + 1 < dist[newValue]:

                dist[newValue] = steps + 1

                q.push({newValue, steps + 1})

    If BFS finishes without reaching end:
        return -1
*/




class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        vector<int> dist(1000, INT_MAX);
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        dist[start] = 0;
        while(!q.empty()){
            auto &[node, steps] = q.front();
            q.pop();
            
            if(node == end) return steps;
            
            for(auto& x : arr){
                int res = (x*node)%1000;
                
                if(dist[res] > steps + 1){
                    dist[res] = steps + 1;
                    q.push({res, dist[res]});
                }
            }
        }
        
        return -1;
    }
};
```