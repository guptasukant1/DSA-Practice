#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>


// $ Search an element in a 2D sorted array

// $ Brute-Force Approach
bool searchMat(vvi &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMat(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}