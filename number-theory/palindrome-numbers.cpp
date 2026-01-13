#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    int rev = 0, temp = num;
    while(temp > 0){
        int last_digit = temp % 10;
        rev = rev * 10 + last_digit;
        temp = temp / 10;
    }

    return rev == num;
}

int main(){
    int number = 4554;
    	
    cout<<(bool)isPalindrome(number);
    	
    return 0;
}