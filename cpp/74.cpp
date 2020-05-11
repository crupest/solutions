#include <vector>

using std::vector;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix.front().empty())
            return false;

        int top_row = 0;
        int bottom_row = matrix.size() - 1;
        while (top_row != bottom_row)
        {
            const int middle_row = (top_row + bottom_row) / 2;
            const int middle_row_p1 = middle_row + 1;
            const int middle_p1_row_front = matrix[middle_row_p1].front();
            if (middle_p1_row_front > target)
            {
                bottom_row = middle_row;
            }
            else if (middle_p1_row_front < target)
            {
                top_row = middle_row_p1;
            }
            else if (middle_p1_row_front == target)
            {
                return true;
            }
        }

        const vector<int> &row = matrix[top_row];

        if (row.size() == 1)
        {
            return row.front() == target;
        }

        int left = 0;
        int right = row.size() - 1;

        while (left != right)
        {
            const int middle = (left + right) / 2;
            const int middle_value = row[middle];
            if (middle_value == target)
            {
                return true;
            }
            else if (middle_value < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return row[left] == target;
    }
};
