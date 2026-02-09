```cpp
#include <iostream>
#include <iomanip>
using namespace std;

double solve(double a, double b){
	double low = 0.0;
	double high = 1e9;
	
	for(int i = 0 ; i < 100 ; ++i){
		double mid = low + (high - low)/2.0;
		
		if(b*mid <= (double)a)
			low = mid;
		else
			high = mid;
	}
	
	return low;
}

int main() {
	int T;
	cin >> T;
	
	while(T--){
		double a, b;
		cin >> a >> b;
		
		double result = solve(a, b);
    	cout << fixed << setprecision(10) << result << endl;
	}

	return 0;
}
```