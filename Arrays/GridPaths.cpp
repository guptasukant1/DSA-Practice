#include<bits/stdc++.h>
using namespace std;

// $ Find out the unique paths from the top-left corner to the bottom-right corner of a grid.
// | The grid is of size m x n. You can only move either down or right at any point in time.


class Solution{
    public:
        // $ Brute Force Approach
        // $ TC: O() | SC: O()
        int count_paths(int i, int j, int n, int m){
            if(i == n - 1 and j == m - 1) return 1;
            if(i >= n || j >= n) return 0;
            else return count_paths(i + 1, j, n, m) + count_paths(i, j + 1, n, m);
        }
        int uniquePaths(int m, int n){
            return count_paths(0, 0, n, m);
        }

};

int main(){
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}