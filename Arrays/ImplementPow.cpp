#include<bits/stdc++.h>
using namespace std;

// $ Implement pow(x, n) | x raised to the power n

// $ Brute Force approach [Recursive] 
// $ Time complexity: O(n)

double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n < 1) return 1/x * myPow(1/x, -(n + 1));
    return n%2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}

int main(){
    cout << myPow(5, 3) << endl;
    return 0;
}
