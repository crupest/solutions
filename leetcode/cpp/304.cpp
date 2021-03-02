#include <vector>

using std::vector;

class NumMatrix {
private:
  std::vector<std::vector<int>> prefix_sum_;

public:
  NumMatrix(vector<vector<int>> &matrix)
      : prefix_sum_(
            matrix.size() + 1,
            std::vector<int>(matrix.empty() ? 1 : matrix.front().size() + 1)) {
    const int row_count = matrix.size();
    const int col_count = matrix.empty() ? 0 : matrix.front().size();

    for (int i = 0; i < row_count; i++)
      for (int j = 0; j < col_count; j++) {
        prefix_sum_[i + 1][j + 1] = prefix_sum_[i][j + 1] +
                                    prefix_sum_[i + 1][j] - prefix_sum_[i][j] +
                                    matrix[i][j];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return prefix_sum_[row1][col1] - prefix_sum_[row2 + 1][col1] -
           prefix_sum_[row1][col2 + 1] + prefix_sum_[row2 + 1][col2 + 1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */