#include <string>

using std::string;

const long long M = 1e9 + 7;

class Solution {
public:
  long long f[100010]{0};

  int numDecodings(string s) {
    f[0] = 1;
    if (s.front() == '*') {
      f[1] = 9;
    } else if (s.front() == '0') {
      f[1] = 0;
    } else {
      f[1] = 1;
    }

    for (int i = 2; i <= s.size(); i++) {
      char c = s[i - 1], l = s[i - 2];
      if (c == '*') {
        f[i] += f[i - 1] * 9;
        if (l == '*') {
          f[i] += f[i - 2] * 15;
        } else if (l == '1') {
          f[i] += f[i - 2] * 9;
        } else if (l == '2') {
          f[i] += f[i - 2] * 6;
        }
        f[i] %= M;
      } else if (c == '0') {
        if (l == '1' || l == '2')
          f[i] += f[i - 2];
        else if (l == '*')
          f[i] += f[i - 2] * 2;
        f[i] %= M;
      } else {
        f[i] += f[i - 1];
        if (l == '*') {
          if (c <= '6')
            f[i] += f[i - 2] * 2;
          else
            f[i] += f[i - 2];
        } else if (l == '1')
          f[i] += f[i - 2];
        else if (l == '2' && c <= '6')
          f[i] += f[i - 2];
        f[i] %= M;
      }
    }

    return f[s.size()] % M;
  }
};
