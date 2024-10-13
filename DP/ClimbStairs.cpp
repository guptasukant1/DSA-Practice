#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Climbing Stairs Problem: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. 
// $ At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.

// $ Tabulation Approach
// $ TC: O(n) | SC: O(n)
int climbBFA(vi &dp,  int n){
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// $ Optimal Approach
// $ TC: O(n) | SC: O(1)
int climbOA(int n){
    int prev2 = 1;
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
    vi dp(n+1,-1);
    cout << climbBFA(dp, n) << endl;
    cout << climbOA(n) << endl;
}