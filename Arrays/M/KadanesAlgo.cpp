#include<bits/stdc++.h>
using namespace std;

// $ Kadane's Algo: Find max sum subarray

// $ BFA
// $ TC: O(n^3) | SC: O(1)
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) { 
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

// $ Better Approach
// $ TC: O(n^2) | SC: O(1)
int maxSubSumBeA(int arr[], int n) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

// $ Optimal Solution
// $ TC: O(n) | SC: O(1)
long long maxSubarraySumOA(int arr[], int n) {
    long long maxi = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    if(maxi < 0) maxi = 0;
    return maxi;
}

// $ Multiple subarrays
// $ TC: O(n) | SC: O(1)
long long maxSubarraySumMS(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;
    for(int i = 0; i < n; i++) {
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum >Finish execution of plan and start working on submission of final report maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "] " << endl;
    if(maxi < 0) maxi = 0;
    return maxi;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    int maxSum1 = maxSubSumBeA(arr, n);
    cout << "The maximum subarray sum is: " << maxSum1 << endl;
    int maxSum2 = maxSubarraySumOA(arr, n);
    cout << "The maximum subarray sum is: " << maxSum2 << endl;
    int maxSum3 = maxSubarraySumMS(arr, n);
    cout << "The maximum subarray sum is: " << maxSum3 << endl;
}