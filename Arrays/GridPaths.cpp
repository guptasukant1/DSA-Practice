#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

// $ Find out the unique paths from the top-left corner to the bottom-right corner of a grid.
// | The grid is of size m x n. You can only move either down or right at any point in time.


class Solution{
public:
    // $ Brute Force Approach
    // $ TC: O(2^(m + n)) | SC: O(m + n) [recursive stack depth]
    int count_paths(int i, int j, int n, int m){
        if(i == n - 1 and j == m - 1) return 1;
        if(i >= n || j >= n) return 0;
        else return count_paths(i + 1, j, n, m) + count_paths(i, j + 1, n, m);
    }
    int uniquePaths(int m, int n){
        return count_paths(0, 0, n, m);
    }

    // $ Better Approach
    // $ TC: O() | SC: O()
    int count_pathsBe(int i, int j, int n, int m, vvi &dp){
        if(i == n - 1 and j == m - 1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = count_pathsBe(i + 1, j, n, m, dp) + count_pathsBe(i, j + 1, n, m, dp);
    }

    int uniquePathsBe(int n, int m){
        vvi dp(n + 1, vi(m + 1, -1));
        int num = count_pathsBe(0, 0, n, m, dp);
        // * dp[1][1] = 1
        if(m == 1 && n == 1) return num;
        return dp[0][0];
    }
};

int main(){
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    Solution o1;
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
    int totalCount1= o1.uniquePathsBe(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount1<<endl;
}