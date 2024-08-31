#include<bits/stdc++.h>
using namespace std;

// $ Maximum sum of non adjacent elements
// | The problem states that we have to find the maximum sum of non adjacent elements in an array.
// | We can either include the current element or we can exclude the current element.
// | If we include the current element then we have to move to the (i + 2)th element. If we exclude the current element then we have to move to the (i + 1)th element.
// | We have to find the maximum of these two choices at every step.
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

int main(){


}