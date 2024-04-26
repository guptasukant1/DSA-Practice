#include<bits/stdc++.h>
using namespace std;

// $ Set zeroes matrix
// $ Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        // for(int i = 0; i < rows; i++){
        //     if(matrix[i][0] == 0) col0 = 0;
        //     for(int j = 0; j < cols; j++){
        //         if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        //     }
        // }

        // for(int i = rows - 1; i >= 0; i--){
        //     for(int j = cols - 1; j >= 1; j--){
        //         if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        //     }
        //     if(col0 == 0) matrix[i][0] = 0;
        // }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;

                    if (j != 0)
                        matrix[0][j] = 0;

                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};


int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    obj.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}