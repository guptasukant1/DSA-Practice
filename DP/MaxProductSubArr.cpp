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

// $ Optimal Approach 1
// $ TC: O() | SC: O()


int main() {
    vi nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums) << endl;
    cout<<"The maximum product subarray: "<<maxPSABe(nums) << endl;
}