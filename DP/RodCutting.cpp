#include<bits/stdc++.h>
using namespace std;

// $ Rod Cutting Problem
// | The problem states that we have to find the maximum profit that can be obtained by cutting the rod into pieces.
// | There is a prices array which contains the price of each piece of the rod.
// | Since overlapping subproblems are there just like in the previous question, we can use dynamic programming to solve this problem.
// | We need to consider the cost of the current segment and the maximum profit that can be obtained from the remaining segment.
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

int main(){


}