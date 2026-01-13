#include <bits/stdc++.h>
using namespace std;

int powr(int a, int b){
    int res = 1;

    while(b){
        if(b&1) res *= a;
        a *= a;
        a /= 2;
    }

    return res;
}

int main(){
    int a = 10, b = 3;
    cout << powr(a, b);
}