#include<bits/stdc++.h>
using namespace std;

// $ Jump Game: Given an array represents the maximum number of steps you can jump forward from that element, return true if reach the last index from first index. Else, return false.
// $ TC: O(n) | SC: O(1)
bool canJump(vector<int> &nums){
    int maxInd = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i > maxInd) return false;
        maxInd = max(maxInd, nums[i] + i);
    }
    return true;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    bool ans = canJump(nums);

    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }
}