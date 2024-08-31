#include<bits/stdc++.h>
using namespace std;


// * LC: 746. Min Cost Climbing Stairs
// | The problem states that we are at the 0th stair and we have to reach the nth stair. We can either take 1 or 2 steps at a time.
// | So, we can either take 1 step and then solve for n-1 or we can take 2 steps and then solve for n-2.
// | The total number of ways to reach the nth stair is equal to sum of total number of ways to reach the (n-1)th stair and total number of ways to reach (n-2)th stair.
// | This is the recursive relation that we have to use to solve this problem. This specific question includes the cost of each step as well.
// $ Count ways to reach nth stair using recursion
// ! TLE due to repeating subproblems
#define mod 1000000007
int countWays(long long n, int i){
    if(i == n){
        return 1;
    }
    if(i > n){
        return 0;
    }

    return (countWays(n, i + 1) + countWays(n, i + 2)) % mod;
}
int countMain(long long n){
    return countWays(n, 0) % mod;
}

// $ Count ways to reach nth stair using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int solveCost(vector<int> &cost, int n, vector<int> &dp){
    if(n <= 1){
        return cost[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = cost[n] + min(solveCost(cost, n - 1), solveCost(cost, n - 2));
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = min(solveCost(cost, n - 1, dp), solveCost(cost, n - 2, dp));
    return ans;
}

// $ Count ways to reach nth stair using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int solveCost1(vector<int> &cost, int n, vector<int> &dp)
{
    int dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++){
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return solveCost1(cost, n, dp);
}
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int dp[n];

//         for(int i=0;i<cost.size();i++) dp[i] = cost[i];

//         for(int i=2;i<n;i++){
//             dp[i] += min(dp[i-1],dp[i-2]);
//         }

//         return min(dp[n-1], dp[n-2]);
//     }
// };

// $ Count ways to reach nth stair using space optimization
// $ TC: O(n)
// $ SC: O(1)
int solveCost2(vector<int> &cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i<n; i++){
        int temp = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = temp;
    }
    return min(prev1, prev2);
}
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    return solveCost1(cost, n);
}

int main(){


}