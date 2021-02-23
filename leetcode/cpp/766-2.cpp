#include <vector>

using std::vector;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int row_count = matrix.size();
    int col_count = matrix.front().size();

    for (int i = 1; i < row_count; i++) {
      for (int j = 1; j < col_count; j++) {
        if (matrix[i][j] != matrix[i - 1][j - 1])
          return false;
      }
    }

    return true;
  }
};