#include <bits/stdc++.h>
using namespace std;

void findDivisors(int n){

    for (int i = 1; i * i <= n; i++){
        if(n%i == 0){
            cout << i << " ";

            if(i != n/i){
                cout << n/i << " ";
            }
        }
    }
}

int main(){
    int number = 36;

    findDivisors(number);

    return 0;
}