#include <vector>

using std::vector;

class Solution
{
public:
    static void dfs(const vector<vector<int>> &grid, bool **visited, int row, int col, int row_max, int col_max, int &current, int &max)
    {
        int cell = grid[row][col];
        bool &cell_visited = visited[row][col];
        if (cell == 0 || cell_visited)
            return;
        current += cell;
        cell_visited = true;

        if (current > max)
            max = current;

        if (row < row_max)
            dfs(grid, visited, row + 1, col, row_max, col_max, current, max);

        if (col < col_max)
            dfs(grid, visited, row, col + 1, row_max, col_max, current, max);

        if (row > 0)
            dfs(grid, visited, row - 1, col, row_max, col_max, current, max);

        if (col > 0)
            dfs(grid, visited, row, col - 1, row_max, col_max, current, max);

        cell_visited = false;
        current -= cell;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int row_max = grid.size();
        int col_max = grid.front().size();

        bool **visited = new bool *[row_max];
        for (int i = 0; i < row_max; i++)
        {
            visited[i] = new bool[col_max]{false};
        }

        int current = 0;
        int max = 0;

        for (int row_start = 0; row_start < row_max; row_start++)
            for (int col_start = 0; col_start < col_max; col_start++)
            {
                dfs(grid, visited, row_start, col_start, row_max - 1, col_max - 1, current, max);
            }

        for (int i = 0; i < row_max; i++)
        {
            delete[] visited[i];
        }
        delete[] visited;

        return max;
    }
};