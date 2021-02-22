#include <vector>

using std::vector;

class Solution {
public:
  void dfs(int N, int index, bool *num_used, int &result) {
    if (index > N) {
      result += 1;
      return;
    }

    for (int num = 1; num <= N; num++) {
      if (!num_used[num] && (num % index == 0 || index % num == 0)) {
        num_used[num] = true;
        dfs(N, index + 1, num_used, result);
        num_used[num] = false;
      }
    }
  }

  int countArrangement(int N) {
    bool *num_used = new bool[N + 1]{false};
    int result = 0;
    dfs(N, 1, num_used, result);
    delete[] num_used;
    return result;
  }
};
