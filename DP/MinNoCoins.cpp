#include<bits/stdc++.h>
using namespace std;

// $ Minimum number of coins to make a given sum
// | The problem states that we have to find the minimum number of coins to make a given sum. We have an infinite supply of coins of different denominations.
// | We can select the given coin by using (target - coins[i]) condition.
// | We have to find the minimum of all the possible choices.
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


int main(){


}