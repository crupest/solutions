#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    const int row_count = matrix.size();
    const int col_count = matrix.front().size();

    vector<vector<int>> result(col_count, std::vector<int>(row_count));

    for (int i = 0; i < row_count; i++)
      for (int j = 0; j < col_count; j++) {
        result[j][i] = matrix[i][j];
      }

    return result;
  }
};
