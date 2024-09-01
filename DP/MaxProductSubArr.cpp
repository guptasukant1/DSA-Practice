#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Maximum Product Sub Array

// $ Brute Force Approach
// $ TC: O(n^3) | SC: O(1)
int maxProductSubArray(vi &nums){
    int res = INT_MIN;
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j < nums.size(); j++){
            int prod = 1;
            for(int k = i; k <= j; k++) prod *= nums[k];
            res = max(res, prod);
        }
    }
    return res;
}

// $ Better Approach
// $ TC: O(n^2) | SC: O(1)
int maxPSABe(vi &nums){
    int res = INT_MIN;
    for(int i = 0; i < nums.size() - 1; i++){
        int prod = nums[i];
        for(int j = i + 1; j < nums.size(); j++){
            res = max(res, prod);
            prod *= nums[j];
        }
        res = max(res, prod); // * To consider the last multiplication for each set of iterations
    }
    return res;
}

// $ Optimal Approach 1 [4 cases: all +ve, even -ve rest +ve, odd -ve rest +ve, 0 present in array]
// $ TC: O(n) | SC: O(1)
int maxPSAOA1(vi &nums){
    int n = nums.size();
    int pre = 1, suff = 1; // * prefix moves from 0 -> n and suffix from n -> 0
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        if(pre == 0) pre =1; // * 0 elem would force to reset the prefix or suffix values whenever encountered
        if(suff == 0) suff =1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main() {
    vi nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums) << endl;
    cout<<"The maximum product subarray: "<<maxPSABe(nums) << endl;
    cout<<"The maximum product subarray: "<<maxPSAOA1(nums) << endl;
}