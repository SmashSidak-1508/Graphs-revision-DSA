#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 && !vis[row][col])
        {
            dfs(row + 1, col, vis, grid);
            dfs(row - 1, col, vis, grid);
            dfs(row, col + 1, vis, grid);
            dfs(row, col - 1, vis, grid);
        }
        // vis[row][col] = 1;
        // queue<pair<int, int>> q;
        // q.push({row, col});
        // while (!q.empty())
        // {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();
        //     // Traverse neighbors
        //     for (int delrow = -1; delrow <= 1; delrow++)
        //     {
        //         for (int delcol = -1; delcol <= 1; delcol++)
        //         {
        //             int nrow = row + delrow;
        //             int ncol = col + delcol;
        //             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
        //             {
        //                 vis[nrow][ncol] = 1;
        //                 q.push({nrow, ncol});
        //             }
        //         }
        //     }
        // }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int counter = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    dfs(row, col, vis, grid);
                    counter++;
                }
            }
        }
        return counter;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution solution;
    int numIslands = solution.numIslands(grid);

    cout << "Number of islands: " << numIslands << endl;

    return 0;
}
