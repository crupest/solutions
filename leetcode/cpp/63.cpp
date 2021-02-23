#include <vector>

using std::vector;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0])
            return 0;
        obstacleGrid[0][0] = 1;

        int row = obstacleGrid.size();
        int col = obstacleGrid.front().size();

        for (int i = 1; i < row; i++)
        {
            obstacleGrid[i][0] = obstacleGrid[i - 1][0] && !obstacleGrid[i][0] ? 1 : 0;
        }

        for (int i = 1; i < col; i++)
        {
            obstacleGrid[0][i] = obstacleGrid[0][i - 1] && !obstacleGrid[0][i] ? 1 : 0;
        }

        for (int r = 1; r < row; r++)
        {
            for (int c = 1; c < col; c++)
            {
                if (obstacleGrid[r][c])
                {
                    obstacleGrid[r][c] = 0;
                }
                else
                {
                    obstacleGrid[r][c] = obstacleGrid[r - 1][c] + obstacleGrid[r][c - 1];
                }
            }
        }

        return obstacleGrid[row - 1][col - 1];
    }
};
