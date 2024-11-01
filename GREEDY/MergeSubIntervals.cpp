#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>

// $ Merge Overlapping Sub Intervals: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals (combined intervals).

// $ Brute Force Approach
// $ TC: O(nlogn + 2n[skipping merged intervals]) | SC: O(n)
vvi mergeOverlappingIntervals(vvi &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vvi ans;
    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j = i + 1; j < n; j++){
            if(arr[j][0] <= end) end = max(arr[j][1], end);
            else break;
        }
        ans.push_back({start, end});
    }
    return ans;
}

// $ Optimal Approach
// $ TC: O(nlogn + n) | SC: O(n)
vvi mergeOverlappingIntervalsOA(vvi &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vvi ans;
    for(int i = 0; i < n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]) ans.push_back(arr[i]);
        else ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
}

int main() {
    vvi arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vvi ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    vvi arr1 = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vvi ans1 = mergeOverlappingIntervals(arr1);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans1) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
}