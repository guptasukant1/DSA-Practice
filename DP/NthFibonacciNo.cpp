#include<bits/stdc++.h>
using namespace std;

// $ nth fibonacci number using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int fib(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }

    // * STEP 3 : Return the state if it is already computed
    if(dp[n] != -1){
        return dp[n];
    }

    // * STEP 2 : Condition for the state computation
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// $ nth fibonacci number using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int fibTabular(int n, vector<int> &dpNew){
    dpNew[0] = 0;
    dpNew[1] = 1;

    for(int i = 2; i <= n; i++){
        dpNew[i] = dpNew[i - 1] + dpNew[i - 2];
    }
    return dpNew[n];
}

// $ nth fibonacci with space optimization
// $ TC: O(n)
// $ SC: O(1)
int fibSpaceOpt(int n){
    int prev1 = 1;
    int prev2 = 0, temp;

    if(n == 0){
        return prev2;
    }

    for(int i = 2; i <= n; i++){
        temp = (prev1 + prev2) % 10;
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1 % 10;
}
