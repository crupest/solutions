#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int row_count = matrix.size();
    int col_count = matrix.front().size();

    if (matrix.size() == 1)
      return true;
    if (matrix.front().size() == 1)
      return true;

    // offset = col - row
    // max(offset) = row_count - 2
    // min(offset) = -(col_count - 2)
    for (int offset = -(col_count - 2); offset <= (row_count - 2); offset++) {
      int row, col;
      if (offset >= 0) {
        row = offset;
        col = 0;
      } else {
        row = 0;
        col = -offset;
      }

      int value = matrix[row][col];
      row++;
      col++;

      while (row < row_count && col < col_count) {
        if (matrix[row][col] != value) {
          return false;
        }
        row++;
        col++;
      }
    }
    return true;
  }
};
