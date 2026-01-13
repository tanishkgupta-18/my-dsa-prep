#include <iostream>
#include <limits.h>
using namespace std;

/*count the trailing zeroes in the factorial and it is governed by 2 and 5 prime factors and we just need count of 5*/
/*Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ....*/
int countTrailingZeros(int n)
{
	int res = 0;

	for(int i=5; i<=n; i=i*5)
	{
		res = res + (n / i);
	}

	return res;
}
int main() {
    
    int number = 251;
    	
    cout<<countTrailingZeros(number);
    	
    return 0;
}