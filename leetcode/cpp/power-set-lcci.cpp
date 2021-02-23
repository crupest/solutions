#include <vector>

using std::vector;

class Solution {
public:
  void dfs(const vector<int> &nums, int index, int size, vector<int> &current,
           vector<vector<int>> &result) {
    if (index ==   size) {
      result.push_back(current);
      return;
    }

    dfs(nums, index + 1, size, current, result);

    current.push_back(nums[index]);
    dfs(nums, index + 1, size, current, result);
    current.pop_back();
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> current;
    vector<vector<int>> result;

    dfs(nums, 0 , nums.size(), current, result);

    return result;
  }
};
