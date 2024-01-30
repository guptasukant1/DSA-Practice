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


// * LC: 746. Min Cost Cli  mbing Stairs
// todo | The problem states that we are at the 0th stair and we have to reach the nth stair. We can either take 1 or 2 steps at a time.
// todo | So, we can either take 1 step and then solve for n-1 or we can take 2 steps and then solve for n-2.
// todo | The total number of ways to reach the nth stair is equal to sum of total number of ways to reach the (n-1)th stair and total number of ways to reach (n-2)th stair.
// todo | This is the recursive relation that we have to use to solve this problem. This specific question includes the cost of each step as well.
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

// $ Minimum number of coins to make a given sum
// todo | The problem states that we have to find the minimum number of coins to make a given sum. We have an infinite supply of coins of different denominations.
// todo | We can select the given coin by using (target - coins[i]) condition.
// todo | We have to find the minimum of all the possible choices.
// $ Minimum number of coins to make a given sum using recursion

int solveRec(vector<int> &num, int x){
    if(x == 0){
        return 0;
    }
    if(x<0) return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i< num.size(); i++){
        int ans = solveRec(num, x - num[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x){
    int ans = solveRec(num, x);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

// $ minimum number of coins to make a given sum using recursion + memoization (top down approach)
// $ TC: O(n*x)
// $ SC: O(x) + O(x) = O(x)
int solveRecMem(vector<int> &num, int x, vector<int> &dp){
    if(x == 0){
        return 0;
    }
    if(x<0) return INT_MAX;

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i = 0; i< num.size(); i++){
        int ans = solveRecMem(num, x - num[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
        }
    }
    dp[x] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x){
    vector<int> dp(x + 1, -1);
    int ans = solveRecMem(num, x, dp);
    if(ans == INT_MAX){
        return -1;
    }
}

// $ minimum number of coins to make a given sum using tabulation (bottom up approach)
// $ TC: O(n*x)
// $ SC: O(x)
int solveTab(vector<int> &num, int x){
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j<num.size(); j++){
            if(i - num[j] >= 0 && dp[i - num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x){
    return solveTab(num, x);
}

// *
// $ minimum number of coins to make a given sum using space optimization
// ! It is meaningless to use space optimization in this problem as we will need to take x variables to satisfy the condition (i - num[j])
// ! This is the same as taking an array of size x
// *


// $ Maximum sum of non adjacent elements
// todo | The problem states that we have to find the maximum sum of non adjacent elements in an array.
// todo | We can either include the current element or we can exclude the current element.
// todo | If we include the current element then we have to move to the (i + 2)th element. If we exclude the current element then we have to move to the (i + 1)th element.
// todo | We have to find the maximum of these two choices at every step.
// !!! Take care in considering the size of dp array. It should be n + 1 for rec + mem and n for tabulation.
// $ Maximum sum of non adjacent elements using recursion
// ! TLE due to repeating subproblems
int solveNARec(vector<int> &nums, int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    int inc = solveNARec(nums, n - 2) + nums[n];
    int exc = solveNARec(nums, n - 1);
    return max(inc, exc);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solveNARec(nums, n - 1);
    return ans;
}

// $ Maximum sum of non adjacent elements using recursion + memoization (top down approach)
// $ TC: O(n)
// $ SC: O(n) + O(n) = O(n)
int solveNARecMem(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return num[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    // $ At any point we have two choices either to include the current element or to exclude it
    // * If we include the current element then we have to move to the (i + 2)th element
    int inc = solveNARecMem(nums, n - 2, dp) + nums[n];
    // * If we exclude the current element then we have to move to the (i + 1)th element
    int exc = solveNARecMem(nums, n - 1, dp);
    dp[n] = max(inc, exc);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> & nums){
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = solveNARecMem(nums, n - 1, dp);
    return ans;
}

// $ Maximum sum of non adjacent elements using tabulation (bottom up approach)
// $ TC: O(n)
// $ SC: O(n)
int solveNATab(vector<int> &num){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        int inc = dp[i - 2] + nums[i];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> & nums){
    return solveNATab(nums, n - 1);
}

// $ Maximum sum of non adjacent elements using space optimization
// $ TC: O(n)
// $ SC: O(1)
int solveNASpaceOpt(vector<int> &num){
    int n = num.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++){
        int inc = prev2 + nums[i];
        int exc = prev1;
        int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> & num){
    return solveNASpaceOpt(num);
}


// $ House Robber Problem
// $ LC: 198. House Robber
// todo | The problem states that we have to find the maximum amount of money that we can rob from the houses.
// todo | We can either rob the current house or we can skip the current house.
// todo | Here, the houses are arranged in a circle. So, we have to take care of the first and the last house.
// todo | If we rob the first house then we cannot rob the last house and vice versa.
// todo | If adjacent houses are robbed then the alarm will ring. So, we have to skip the adjacent houses.
// todo | If we consider the first house, then we find the solution without the last house and same for the last house
// $ House Robber Problem using space optimization
int solveHR(vector<int> &vecCase){
    int n = vecCase.size();
    int prev2 = 0;
    int prev1 = vecCase[0];

    for(int i = 1; i < n; i++){
        int inc = prev2 + vecCase[i];
        int exc = prev1;
        int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int houseRobber(vector<int> &value){
    int n = value.size();
    if(n == 1) return value[0];
    if(n == 2) return max(nums[0], nums[1]);
    return solveHR(nums);
    // * The commented section is required only if the houses are arranged in a circle
    // vector<int> first, second;
    // for(int i = 0; i < n; i++){
    //     if(i != n-1) first.push_back(value[i]);
    //     if(i != 0) second.push_back(value[i]);
    // }
    // return max(solveHR(first), solveHR(second));
    // ********************************************
}


// $ Cut into Segments of x, y, z Problem
// todo | The problem states that we have to find the maximum number of segments that can be formed from the given length of the stick.
// todo | We have to cut the stick into segments of length a, b and c.
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



// $ Rod Cutting Problem
// todo | The problem states that we have to find the maximum profit that can be obtained by cutting the rod into pieces.
// todo | There is a prices array which contains the price of each piece of the rod.
// todo | Since overlapping subproblems are there just like in the previous question, we can use dynamic programming to solve this problem.
// todo | We need to consider the cost of the current segment and the maximum profit that can be obtained from the remaining segment.
int cutRod(int price[], int n){
    int dp[n + 1];
    dp[0] = 0;

    // $ This loop is for the length of the rod
    for(int i = 1; i < n; i++){
        int maxVal = INT_MIN;
        // $ This loop is for the cuts that can be made in the rod
        for (int j = 0; j < i; j++){
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
            // $ i - j - 1 is the remaining length of the rod and j is the length of the current cut
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

// $ Count Derangements Problem. CN Platform
// todo | The problem states that we have to find the number of derangements of n objects.
// todo | Derangement means that no object is in its original position.
// todo | first case: To swap the first element with any of the remaining n - 1 elements. So, we have ans as (n - 1) * solve(n - 2)
// todo | Indexes remaining are n - 2 because we have already used two indexes and we have to find the derangement of the remaining n - 2 elements.
// todo | second case: To swap the first element with the n - 1th element and then swapping the n - 1th element with another element. So, we have ans as solve(n - 1)
// todo | Indexes remaining are n - 1 because we have already used one index and we have to find the derangement of the remaining n - 1 elements.
// todo | Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return.
// todo | i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
// todo | i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices.
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

int main()
{
    int n;
    cin >> n;
    // * STEP 1 : Create a dp array
    vector<int> dp(n + 1, -1);
    vector<int> dpNew(n + 1);

    cout << fib(n, dp) << endl;

    cout << fibTabular(n, dpNew) << endl;

    cout << fibSpaceOpt(n) << endl;
    vector<int> num = {9, 6, 5, 1};
    cout << minimumElements(num, 20) << endl;
}