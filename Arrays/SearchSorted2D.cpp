#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

// $ Search an element in a 2D sorted array

// $ Brute-Force Approach
// $ TC: O(n*m) | SC: O(1)
bool searchMat(vvi &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}

// $ Better Approach[Binary Search - selective search - check the row where the target may be and then apply binary search there]
// $ TC: O(n + logm) | SC: O(1)
// ! Fails for [[1]], as it is being considered via 2d index of the matrix
bool BinarySearch(vi &nums, int target){
    int n = nums.size();
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return true;
        else if(target < nums[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
bool searchMatBe(vvi &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0; i < n; i++){
        if(target >= matrix[i][0] && target < matrix[i][m - 1]) return BinarySearch(matrix[i], target);
    }
    return false;
}


// $ Optimal Approach[Flattening the matrix - assume the 2d matrix is 1d and the indices of the 2d are to be mapped to the 1d array by taking the nos of cols value]
// $ TC: O(log(n*m)) | SC: O(1)
bool searchMatOA(vvi &matrix, int target){
    int n = matrix.size(), m = matrix[0].size();

    int low = 0, high = n * m - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / m, col = mid % m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}


int main(){
    vvi matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMat(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchMatBe(matrix, 13) == true ? cout << "true\n" : cout << "false\n";
    searchMatOA(matrix, 1) == true ? cout << "true\n" : cout << "false\n";
}