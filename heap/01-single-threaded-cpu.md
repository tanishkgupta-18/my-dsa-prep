```cpp
vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();

    vector<tuple<int,int,int>> arr;
    for(int i = 0; i < n; ++i)
        arr.push_back({tasks[i][0], tasks[i][1], i});

    sort(arr.begin(), arr.end());  // by enqueueTime

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> ans;
    long long time = 0;
    int i = 0;

    while(i < n || !pq.empty()) {

        if(pq.empty())
            time = max(time, (long long)get<0>(arr[i]));

        while(i < n && get<0>(arr[i]) <= time) {
            pq.push({get<1>(arr[i]), get<2>(arr[i])});
            i++;
        }

        auto [pt, idx] = pq.top();
        pq.pop();

        time += pt;
        ans.push_back(idx);
    }

    return ans;
}
```