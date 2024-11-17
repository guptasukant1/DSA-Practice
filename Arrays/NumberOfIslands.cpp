#include<bits/stdc++.h>
using namespace std;
#define vvc vector<vector<char>>
#define vc vector<char>

// $ Number of Islands from a grid (1 = island | 0 = water)

class Solution{
    public:
    void DFS(vvc &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == '2') return;

        grid[i][j] = '2';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    int numIslands(vvc &grid){
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    // Example grid
    vvc grid = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'1', '1', '0', '1', '1'}
    };

    Solution solution;
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl; 

    return 0;
}