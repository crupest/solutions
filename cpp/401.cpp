#include <array>
#include <string>
#include <vector>

using std::string;
using std::vector;

const std::array<int, 4> hour_digits{1, 2, 4, 8};
const std::array<int, 6> minute_digits{1, 2, 4, 8, 16, 32};

class Solution {
public:
  template <int max, std::size_t size>
  void dfs(const std::array<int, size> &digits, int total_count, int rest_count,
           int start_index, int value, std::vector<int> &result) {

    if (value >= max)
      return;

    if (rest_count == 0) {
      result.push_back(value);
      return;
    }

    for (int i = start_index; i <= size - rest_count; i++) {
      dfs<max, size>(digits, total_count, rest_count - 1, i + 1,
                     value + digits[i], result);
    }
  }

  vector<string> readBinaryWatch(int num) {
    vector<string> results;

    for (int i = (num > 6 ? num - 6 : 0); i <= (num > 4 ? 4 : num); i++) {
      std::vector<int> hours;
      std::vector<int> minutes;
      if (i == 0)
        hours = {0};
      else
        dfs<12>(hour_digits, i, i, 0, 0, hours);
      if (i == num)
        minutes = {0};
      else
        dfs<60>(minute_digits, num - i, num - i, 0, 0, minutes);

      for (auto hour : hours) {
        for (auto minute : minutes) {
          char buffer[6];
          sprintf(buffer, "%d:%02d", hour, minute);
          results.push_back(string(buffer));
        }
      }
    }

    return results;
  }
};
