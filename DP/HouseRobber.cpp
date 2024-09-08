#include<bits/stdc++.h>
using namespace std;

// $ House Robber Problem
// $ LC: 198. House Robber
// | The problem states that we have to find the maximum amount of money that we can rob from the houses.
// | We can either rob the current house or we can skip the current house.
// | Here, the houses are arranged in a circle. So, we have to take care of the first and the last house.
// | If we rob the first house then we cannot rob the last house and vice versa.
// | If adjacent houses are robbed then the alarm will ring. So, we have to skip the adjacent houses.
// | If we consider the first house, then we find the solution without the last house and same for the last house
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

int main(){


}
