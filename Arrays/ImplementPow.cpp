#include<bits/stdc++.h>
using namespace std;

// $ Implement pow(x, n) | x raised to the power n

// $ Brute Force approach [Recursive] 
// $ TC: O(n) | SC: O(1) 
double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n < 1) return 1/x * myPow(1/x, -(n + 1));
    return n%2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}

// $ Brute-Force Approach [Loops]
// $ TC: O(n) | SC: (1)
double myPowBF(double x, int n){
    double ans = 1.0;
    for(int i = 0; i < n; i++) ans *= x;
    return ans;
}

// $ Optimal Solution [Binary Exponentiation]
// $ TC: O() | SC: O()
double myPowOA1(double x, int n){
    
}



int main(){
    cout << myPow(5, 3) << endl;
    cout << myPowBF(5, 3) << endl;
    return 0;
}
