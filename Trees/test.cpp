#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    int x = 1, k;
    if(n == 1)
        return x;
    for(k = 1; k < n; ++k){
        x = x + fun(k) * fun(n - k);
        // cout<< k << " " << n << " " << x << endl;
    }
    return x;
}

int main(){
    cout << fun(5);
}..