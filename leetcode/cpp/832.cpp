#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    const int row_count = A.size();
    const int col_count = A.front().size();
    std::vector<std::vector<int>> result(row_count,
                                         std::vector<int>(col_count));
    for (int i = 0; i < row_count; i++) {
      for (int j = 0; j < col_count; j++) {
        result[i][j] = !A[i][col_count - j - 1];
      }
    }

    return result;
  }
};
