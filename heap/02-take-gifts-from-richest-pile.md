```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (auto& g : gifts) {
            pq.push(g);
        }

        while (k--) {
            int g = pq.top();
            pq.pop();

            int val = sqrt(g);
            pq.push(val);
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
```