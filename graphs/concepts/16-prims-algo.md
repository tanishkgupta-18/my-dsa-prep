```cpp
#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    vector<bool> inMST(V,false);

    pq.push({0,0}); // {weight,node}

    int mstWeight = 0;

    while(!pq.empty())
    {
        auto [wt,u] = pq.top();
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;
        mstWeight += wt;

        for(auto &[v,weight] : adj[u])
        {
            if(!inMST[v])
            pq.push({weight,v});
        }
    }

    return mstWeight;
}

int main()
{
    int V = 4;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,5});
    adj[1].push_back({0,5});

    adj[0].push_back({2,8});
    adj[2].push_back({0,8});

    adj[1].push_back({2,10});
    adj[2].push_back({1,10});

    adj[1].push_back({3,15});
    adj[3].push_back({1,15});

    adj[2].push_back({3,20});
    adj[3].push_back({2,20});

    cout << primMST(V,adj);
}
```