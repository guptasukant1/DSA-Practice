#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

// $ Rotate Matrix
// | Given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// $ Brute-Force: Maintain 2 loops, one for row and one for column. Traverse the matrix and copy the elements to the new matrix in the rotated position.
// $ Time Complexity: O(n^2)
vvi rotateMatrix(vvi &matrix)
{
    int n = matrix.size();
    vvi rotatedM(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotatedM[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotatedM;
}

// $ Optimal Approach: Transpose the matrix and then reverse the rows.
// $ Time Complexity: O(n^2) [Yes, this is in fact the best case solution as it has 0ms runtime]
void rotateMatrix1(vvi &matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
        // ! Swap/Transpose only bottom left triangular array
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vvi arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vvi rotated = rotateMatrix(arr);
    int n = rotated.size();
    cout << "Rotated: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << "\n";
    }

    vvi arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix1(arr1);
    cout << "Rotated Optimal: " << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[0].size(); j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }
}