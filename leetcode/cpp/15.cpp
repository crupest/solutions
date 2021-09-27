#include <iterator>
#include <vector>

using std::vector;

#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

bool operator<(const std::vector<int> &l, std::vector<int> &r) {
  return std::lexicographical_compare(l.cbegin(), l.cend(), r.cbegin(),
                                      r.cend());
}

class Solution {
public:
  int ha[100010]{0};

  vector<vector<int>> threeSum(vector<int> &nums) {
    std::set<std::vector<int>> result;

    if (nums.size() < 3)
      return {};

    std::unordered_map<int, int> m;

    for (auto n : nums) {
      if (n >= 0)
        m[n]++;
    }

    for (int i = 0; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        auto v = -nums[i] - nums[j];
        if (v == 0) {
          
        }
      }
    }

    return std::vector<vector<int>>(result.cbegin(), result.cend());
  }
};