#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }
    return n * fact(n - 1);
}

int power(int n){
    if(n == 0){
        return 1;
    }

    return 2 * power(n - 1);
}

void printCount(int n){
    if(n == 0){
        return ;
    }
    cout << n << endl;
    printCount(n - 1);
}

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << fact(n) << endl;

    int ans = power(n);
    cout << ans << endl;
    // printCount(n);

    cout << fib(n) << endl;

}