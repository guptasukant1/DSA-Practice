#include<bits/stdc++.h>
using namespace std;

// $ Cut into Segments of x, y, z Problem
// | The problem states that we have to find the maximum number of segments that can be formed from the given length of the stick.
// | We have to cut the stick into segments of length a, b and c.
// $ Cut into Segments of x, y, z Problem using recursion
// ! TLE due to repeating subproblems
int solveCSRec(int n, int x, int y, int z){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    int a = 1 + solveCSRec(n - x, x, y, z);
    int b = 1 + solveCSRec(n - y, x, y, z);
    int c = 1 + solveCSRec(n - z, x, y, z);

    int ans = max(a, max(b, c));
    return ans;
}
int cutSegments(int n, int x, int y, int z){
    int ans = solveCSRec(n, x, y, z);
    if(ans < 0) return 0;
    return ans;
}

// $ Cut into Segments of x, y, z Problem using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int solveCSRecMem(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    if(dp[n] != -1) return dp[n];

    int a = 1 + solveCSRecMem(n - x, x, y, z, dp);
    int b = 1 + solveCSRecMem(n - y, x, y, z, dp);
    int c = 1 + solveCSRecMem(n - z, x, y, z, dp);

    dp[n] = max(a, max(b, c));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z){
    vector<int> dp(n + 1, -1);
    int ans = solveCSRecMem(n, x, y, z, dp);
    if(ans < 0) return 0;
    return ans;
}

// $ Cut into Segments of x, y, z Problem using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int solveCSTab(int n, int x, int y, int z){
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        if(i - x >= 0) dp[i] = max(dp[i], dp[i - x] + 1);
        if(i - y >= 0) dp[i] = max(dp[i], dp[i - y] + 1);
        if(i - z >= 0) dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if(dp[n] < 0) return 0;
    return dp[n];
}
int cutSegments(int n, int x, int y, int z){
    int ans = solveCSTab(n, x, y, z);
}

// $ Cut into Segments of x, y, z Problem using space optimization
// ! It is meaningless to use space optimization in this problem as we will need to take n variables to satisfy the condition (i - x)
// ! This is the same as taking an array of size n

int main(){


}