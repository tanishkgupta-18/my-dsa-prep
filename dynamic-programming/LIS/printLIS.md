```cpp
vector<int> printLIS(vector<int>& nums){

    int n=nums.size();

    vector<int> dp(n,1);

    vector<int> parent(n);

    for(int i=0;i<n;i++)
        parent[i]=i;

    int lastIndex=0;

    for(int i=0;i<n;i++){

        for(int j=0;j<i;j++){

            if(nums[j]<nums[i]
               &&
               dp[j]+1>dp[i]){

                dp[i]=dp[j]+1;

                parent[i]=j;
            }
        }

        if(dp[i]>dp[lastIndex])
            lastIndex=i;
    }

    vector<int> lis;

    while(parent[lastIndex]!=lastIndex){

        lis.push_back(
            nums[lastIndex]
        );

        lastIndex=
            parent[lastIndex];
    }

    lis.push_back(
        nums[lastIndex]
    );

    reverse(
        lis.begin(),
        lis.end()
    );

    return lis;
}
```