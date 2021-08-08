/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
*/
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        return;
    grid[i][j] = '2';
    dfs(grid, i+1, j, n, m);
    dfs(grid, i-1, j, n, m);
    dfs(grid, i, j+1, n, m);
    dfs(grid, i, j-1, n, m);
    dfs(grid, i+1, j+1, n, m);
    dfs(grid, i-1, j+1, n, m);
    dfs(grid, i+1, j-1, n, m);
    dfs(grid, i-1, j-1, n, m);
}

int numberOfIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if(n == 0)
        return 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1')
            {
                dfs(grid, i, j, n, m);
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> grid = {{'0','1','1','1','0','0','0'},
                                 {'0','0','1','1','0','1','0'}};
    int ans = numberOfIslands(grid);
    cout << ans;
    return 0;
}