#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Memoization Approach
// $ TC: O(N) | SC: O(N + n)
int fib(int n, vi& dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

// $ Tabulation Approach
// $ TC: O(n) | SC: O(n)
int fib1(int n, vi &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// $ Optimal Approach
// $ TC: O(n) | SC: O(1)
int fib2(int n){
    int prev2 = 0;
    int prev1 = 1;
    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 5;
    vector<int> dp(n+1,-1);
    vector<int> dp1(n+1,-1);
    cout<<fib(n,dp) << endl;
    cout << fib1(n, dp1) << endl;
    cout << fib2(n) << endl; 
}
