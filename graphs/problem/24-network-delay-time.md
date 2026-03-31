```cpp
class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);
        const int INF = 1e9;
        for(auto& e : edges){
            adjList[e[0]].push_back({e[1], e[2]});
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INF);
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for(auto& [v, w] : adjList[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int maxTime = -1;
        for(auto& t : dist){
            if(t == INF) return -1;
            
            maxTime = max(maxTime, t);
        }
        
        return maxTime;
    }
};
```