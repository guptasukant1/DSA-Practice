#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>

// $ Overlapping Subintervals
// todo | Given a list of intervals, find the number of intervals that are there in the list which overlap with each other.

// $ Brute Force Approach
// $ TC: O(nlogn) + O(2*n) [sort + 2 loops iteration, however we are skipping the intervals that are already merged with the previous intervals]
vvi mergeOverlap(vvi &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vvi ans;
    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j = i + 1; j < n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
    }
}

int main(){
    vvi arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vvi ans = mergeOverlap(arr);
    cout << "The merged intervals are: "
         << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}