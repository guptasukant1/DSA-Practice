#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
double myPowOA(double x, int n){
    double ans = 1.0;
    ll nn = n;
    if(nn < 0) nn = -1 * nn;
    while(nn){
        if(nn % 2 == 1){ // * or (n % 2)
            ans *= x;
            nn = nn - 1;
        }
        else{
            x *= x;
            nn = nn / 2;
        }
    }
    if(n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

int main(){
    cout << myPow(5, 3) << endl;
    cout << myPowBF(4, 3) << endl;
    cout << myPowOA(2, 6) << endl;
    cout << myPowOA(4, 3) << endl;
    return 0;
}