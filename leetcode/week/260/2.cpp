#include <vector>

using std::vector;

#include <iterator>
#include <limits>
#include <numeric>

class Solution {
public:
  long long gridGame(vector<vector<int>> &grid) {
    int s = grid.front().size();
    std::vector<long long> row0(grid[0].cbegin(), grid[0].cend());
    std::vector<long long> row1(grid[1].cbegin(), grid[1].cend());
    std::vector<long long> ps0, ps1;

    std::partial_sum(row0.cbegin(), row0.cend(), std::back_inserter(ps0));
    std::partial_sum(row1.cbegin(), row1.cend(), std::back_inserter(ps1));

    long long r = std::numeric_limits<long long>::max();

    for (int i = 0; i < s; i++) {
      long long c = std::max(ps0.back() - ps0[i], i ? ps1[i - 1] : 0);
      r = std::min(r, c);
    }

    return r;
  }
};