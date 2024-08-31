#include<bits/stdc++.h>
using namespace std;

// $ Count Derangements Problem. CN Platform
// | The problem states that we have to find the number of derangements of n objects.
// | Derangement means that no object is in its original position.
// | first case: To swap the first element with any of the remaining n - 1 elements. So, we have ans as (n - 1) * solve(n - 2)
// | Indexes remaining are n - 2 because we have already used two indexes and we have to find the derangement of the remaining n - 2 elements.
// | second case: To swap the first element with the n - 1th element and then swapping the n - 1th element with another element. So, we have ans as solve(n - 1)
// | Indexes remaining are n - 1 because we have already used one index and we have to find the derangement of the remaining n - 1 elements.
// | Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return.
// | i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
// | i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices.
// $ Count Derangements Problem using recursion
// ! TLE due to repeating subproblems
#define MOD 1000000007
long long int CountDer(int n){
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;

    return ((n - 1)%MOD * (CountDer(n - 2)%MOD + CountDer(n - 1)%MOD)) %MOD;
}

// $ Count Derangements Problem using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int solveCDRecMem(int n, vector<long long int> &dp)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = ((n - 1) % MOD * (solveCDRecMem(n - 2, dp) % MOD + solveCDRecMem(n - 1, dp) % MOD)) % MOD;
    return dp[n];
}
long long int CountDer(int n)
{
    vector<long long int> dp(n + 1, -1);
    return solveCDRecMem(n, dp);
}
// $ Count Derangements Problem using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int solveCDTab(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) % MOD * sum) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}
long long int CountDer(int n)
{
    return solveCDTab(n);
}
// $ Count Derangements Problem using Space Optimization
// $ TC: O(n)
// $ SC: O(1)
int solveCDSpaceOpt(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int ans = ((i - 1) % MOD * (prev1 % MOD + prev2 % MOD) % MOD) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int CountDer(int n)
{
    return solveCDSpaceOpt(n);
}

int main(){


}