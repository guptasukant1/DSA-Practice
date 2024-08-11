#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Trapping Water Problem

// $ Brute Force Approach [finding the maximum left and right at each index and calculate the water trapped at that index]
// $ TC: O(n ^ 2) | SC: O(1)
int trap(vi &arr){
    int n = arr.size();
    int water = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        int leftMax = 0, rightMax = 0;
        while(j >= 0){
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while(j < n){
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        water += min(leftMax, rightMax) - arr[i];
    }
    return water;
}

// $ Better Approach [using prefix and suffix array to find the max left and right at each index and reduce tc by calculating them individually]
// $ TC: O(3 * n) | SC: O(2 * n)
int trapBeA(vi &arr){
    int n = arr.size();
    int prefix[n], suffix[n];
    // * Calculate prefix and suffix arrays by setting at start for prefix and at end for suffix
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = max(prefix[i - 1], arr[i]);
    suffix[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) suffix[i] = max(suffix[i + 1], arr[i]);

    int water = 0;
    for(int i = 0; i < n; i++) water += min(prefix[i], suffix[i]) - arr[i];
    return water;
}

// $ Optimal Approach [2 pointer approach -> set ptrs at ends, finding left and right max to to find whether water is trapped at the left or right end and adding to res]
// $ [and avoiding separate calc of max left and right at each index]
// $ TC: O(n) | SC: O(1)
int trapOA(vi &arr){
    int n = arr.size();
    int left = 0, right = n - 1;
    int res = 0, maxLeft = 0, maxRight = 0;
    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= maxLeft) maxLeft = arr[left];
            else res += maxLeft - arr[left];
            left++;
        }
        else{
            if(arr[right] >= maxRight) maxRight = arr[right];
            else res += maxRight - arr[right];
            right--;
        }
    }
    return res;
}

int main() {
    vi arr;
    arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
    cout << "The water that can be trapped is " << trapBeA(arr) << endl;
    cout << "The water that can be trapped is " << trapOA(arr) << endl;
}