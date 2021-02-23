#include <vector>

using std::vector;

class Solution {
public:
  void dfs(const vector<int> &nums, vector<int> &current, bool *num_used,
           vector<vector<int>> &result) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!num_used[i]) {
        num_used[i] = true;
        current.push_back(nums[i]);
        dfs(nums, current, num_used, result);
        current.pop_back();
        num_used[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> current;
    vector<vector<int>> result;
    bool *num_used = new bool[nums.size()]{false};
    dfs(nums, current, num_used, result);
    delete[] num_used;

    return result;
  }
};
