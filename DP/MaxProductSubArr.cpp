#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Maximum Product Sub Array

// $ Brute Force Approach
// $ TC: O(n^3) | SC: O(1)
int maxProductSubArray(vi &nums){
    int res = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            int prod = 1;
            for(int k = i; k <= j; k++) prod *= nums[k];
            res = max(res, prod);
        }
    }
    return res;
}





int main() {
    vi nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}