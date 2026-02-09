```cpp
int sumExists(int arr[], int N, int sum) {
    unordered_map<int, int> mp;
    
    for(int i = 0 ; i < N ; ++i){
        int complement = sum - arr[i];
        
        if(mp.find(complement) != mp.end()) return 1;
        
        mp[arr[i]] = i;
    }
    
    return 0;
}
```