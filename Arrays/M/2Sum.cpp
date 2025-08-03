#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ 2 Sum: 1st -> T or F for 2 nos to give target. 2nd -> Get those 2 nos indices

// $ BFA 1st
// $ TC: O(n^2) | SC: O(1)
string twoSum1(int n, vector<int> &arr, int target) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

// $ BFA 2nd
// $ TC: O(n^2) | SC: O(1)
vi twoSum2(int n, vector<int> &arr, int target) {
    vi temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                temp.push_back(i);
                temp.push_back(j);
                return temp;
            }
        }
    } 
    return {-1, -1};
}

// $ Better Approach
// $ TC: O(n) | SC: O(n)
string twoSum1BeA(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        if(mpp.find(target - arr[i]) != mpp.end()) {
            return "YES";
        }
        mpp[arr[i]] = i;
    }
    return "NO";
}

// $ Better Approach 2nd
// $ TC: O(n) | SC: O(n)
vi twoSum2BeA(int n, vi &arr, int target) {
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        if(mpp.find(target - arr[i]) != mpp.end()) {
            return {mpp[target - arr[i]], i};
        }
        mpp[arr[i]] = i;
    }
    return {-1, -1};
}

// $ Optimal Approach
// $ TC: O(n + nlogn) | SC: O(1)
string twoSum1OA(int n, vi &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            return "YES";
        }
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}

// $ Optimal Approach 2nd
// $ TC: O(n + nlogn) | SC: O(2)
// ! Indices are off !!!
vi twoSum2OA(int n, vi &arr, int target) {
    vector<pair<int, int>> vpii;
    for(int i = 0; i < n; i++) {
        vpii.push_back({arr[i], i});
    }
    sort(vpii.begin(), vpii.end());
    int left = 0, right = n - 1;
    while(left < right) {
        int sum = vpii[left].first + vpii[right].first;
        if(sum == target) return {vpii[left].second, vpii[right].second};
        else if(sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    int n = 5;
    vector<int> arr = {5, 6, 7, 1, 9};
    int target = 14;

    string ans = twoSum1(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;

    vi ans1 = twoSum2(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans1[0] << ", " << ans1[1] << "]" << endl;

    string ans2 = twoSum1BeA(n, arr, target);
    cout << "This is the answer for variant 1: " << ans2 << endl;

    vi ans21 = twoSum2BeA(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans21[0] << ", " << ans21[1] << "]" << endl;

    string ans3 = twoSum1OA(n, arr, target);
    cout << "This is the answer for variant 1: " << ans3 << endl;

    vi ans31 = twoSum2OA(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans31[0] << ", " << ans31[1] << "]" << endl;
}