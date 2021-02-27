#include <array>
#include <string>

using std::string;

class Solution {
public:
  static int dfs(const std::string &s, int start, int end, int k) {
    if (end - start < k) {
      return 0;
    }

    std::array<int, 26> counts{0};

    for (int i = start; i < end; i++) {
      counts[s[i] - 'a']++;
    }

    int max = -1;

    for (char c = 'a'; c <= 'z'; c++) {
      int count = counts[c - 'a'];

      if (count > 0 && count < k) {
        int sub_start = start;

        for (int i = start; i < end; i++) {
          if (s[i] == c) {
            if (sub_start != i) {
              max = std::max(dfs(s, sub_start, i, k), max);
            }
            sub_start = i + 1;
          }
        }

        if (sub_start != end) {
          max = std::max(dfs(s, sub_start, end, k), max);
        }

        break; // This is vital.
      }
    }

    if (max == -1)
      return end - start;
    else
      return max;
  }

  int longestSubstring(string s, int k) { return dfs(s, 0, s.size(), k); }
};

int main() {
  Solution{}.longestSubstring("aaaaaaaaaaaabcdefghijklmnopqrstuvwzyz", 3);
  return 0;
}
