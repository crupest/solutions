#include <vector>

using std::vector;

#include <algorithm>

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int row_count = grid.size();
        int col_count = grid.front().size();

        for (int i = 1; i < row_count; i++)
        {
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < col_count; j++)
        {
            grid[0][j] = grid[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < row_count; i++)
        {
            for (int j = 1; j < col_count; j++)
            {
                grid[i][j] = std::max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[row_count - 1][col_count - 1];
    }
};
