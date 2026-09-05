```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : arr)
            pq.push(x);

        int cost = 0;

        while(pq.size() > 1) {

            int rope1 = pq.top();
            pq.pop();

            int rope2 = pq.top();
            pq.pop();

            int newRope = rope1 + rope2;

            cost += newRope;

            pq.push(newRope);
        }

        return cost;
    }
};
```