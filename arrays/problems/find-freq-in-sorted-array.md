```cpp
void printFreq(vector<int>& arr){
	int n = arr.size();
	
	for(int i = 0 ; i < n ;){
		int j = i;
		while(j+1 < n && arr[j] == arr[j+1]){
			j++;
		}
		
		cout <<arr[i] << ":" << j-i+1 << '\n';
		
		i = j+1;
	}
}
```