#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    int count = 0;

    while(n > 0){
        n /= 10;
        count++;
    }

    return count;
}

int main(){
    int number = 789;
    	
    cout<<countDigits(number);

    return 0;
}