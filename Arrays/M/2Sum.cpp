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
// $ TC: O() | SC: O()
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

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    string ans = twoSum1(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;

    vi ans1 = twoSum2(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans1[0] << ", " << ans1[1] << "]" << endl;

    string ans2 = twoSum1BeA(n, arr, target);
    cout << "This is the answer for variant 1: " << ans2 << endl;
}