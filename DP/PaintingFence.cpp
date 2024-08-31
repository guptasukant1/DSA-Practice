#include<bits/stdc++.h>
using namespace std;

// $ Painting Fence Problem
// | The problem states that we have to find the number of ways to paint the fence with k colors.
// | We have to paint the fence with k colors such that no more than two adjacent fences have the same color.
// | 1st way to paint: last 2 posts are same. So, we have ans as (k - 1) * solve(n - 2, k). n - 2 will give us 2 remaining posts
// | Here, the n - 2 posts have set colours, and the last 2 are supposed to be same, and that will have k - 1 available colours.
// | 2nd way to paint: last 2 posts are different. So, we have ans as (k - 1) * solve(n - 1, k). n - 1 will give us 1 remaining post
// | Here, the n - 1 posts have set colours, but the last is supposed to be different, and that will have k - 1 available colours.
// $ Painting Fence Problem using recursion
// ! TLE due to repeating subproblems
#define mod 1000000007

int add(int a, int b){
    return (a % mod + b % mod) % mod;
}
int multiply(int a, int b){
    return (a % mod * b % mod) % mod;
}
int solveFPRec(int n, int k){
    if(n == 0) return 0;
    if(n == 1) return k;
    if(n == 2) return add(k, multiply(k, k - 1));

    int same = multiply(solveFPRec(n - 2, k), k - 1);
    int diff = multiply(solveFPRec(n - 1, k), k - 1);
    int ans = add(same, diff);
    return ans;
}
int numberOfWays(int n, int k){
    return solveFPRec(n, k);
}
// $ Painting Fence Problem using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int solveFPRecMem(int n, int k, vector<long long> &dp){
    if(n == 0) return 0;
    if(n == 1) return k;
    if(n == 2) return add(k, multiply(k, k - 1));

    if(dp[n] != -1) return dp[n];

    int same = multiply(solveFPRecMem(n - 2, k, dp), k - 1);
    int diff = multiply(solveFPRecMem(n - 1, k, dp), k - 1);
    dp[n] = add(same, diff);
    return dp[n];
}
int numberOfWays(int n, int k){
    vector<long long> dp(n + 1, -1);
    return solveFPRecMem(n, k, dp);
}
// $ Painting Fence Problem using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int solveFPTab(int n, int k){
    vector<long long> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, multiply(k, k - 1));

    for(int i = 3; i <= n; i++){
        long long same = multiply(dp[i - 2], k - 1);
        long long diff = multiply(dp[i - 1], k - 1);
        dp[i] = add(same, diff);
    }
    return dp[n];
}
int numberOfWays(int n, int k){
    return solveFPTab(n, k);
}

// $ Painting Fence Problem using space optimization
// $ TC: O(n)
// $ SC: O(1)
int solveFPspaceOpt(int n, int k){
    if( n == 1) return k;
    long long prev2 = k;
    long long prev1 = add(k, multiply(k, k - 1));

    for(int i = 3; i <= n; i++){
        long long same = multiply(prev2, k - 1);
        long long diff = multiply(prev1, k - 1);
        long long ans = add(same, diff);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k){
    return solveFPspaceOpt(n, k);
}

int main(){


}