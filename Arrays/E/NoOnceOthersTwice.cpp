#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Brute Force
// $ TC: O(n^2) | SC: O(1)
int singleElem(vi &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == num) cnt++;
        }
        if(cnt == 1) return num;
    }
    return -1;
}

// $ Better Approach 1
// $ TC: O(n) | SC: O(maxi)
int singleElemBeA(vi &arr) {
    int n = arr.size();
    int maxi = arr[0];
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    vi hash(maxi + 1, 0);
    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(hash[arr[i]] == 1) return arr[i];
    }

    return -1;
}

// $ Better Approach 2
// $ TC: O(n*logn) | SC: O(n)
int singleElemBeA1(vi &arr) {
    int n = arr.size();

    map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for(auto it : mpp) {
        if(it.second == 1) return it.first;
    }

    return -1;
}

// $ Optimal Approach
// $ TC: O(n) | SC: O(1)
int singleElemOA(vi &arr) {
    int n = arr.size();
    int xo = 0;
    for(int i = 0; i < n; i++) {
        xo = xo ^ arr[i];
    }
    return xo;
}

int main() {
    vi arr = {4, 1, 2, 1, 2};
    int ans = singleElem(arr);
    cout << "The single element is: " << ans << endl;
    int ans1 = singleElemBeA(arr);
    cout << "The single element is: " << ans1 << endl;
    int ans2 = singleElemBeA1(arr);
    cout << "The single element is: " << ans2 << endl;
    int ans3 = singleElemOA(arr);
    cout << "The single element is: " << ans3 << endl;
}