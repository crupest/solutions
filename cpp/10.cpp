#include <string>
#include <unordered_map>
#include <vector>

using std::string;

struct Token {
  explicit Token(char c) : c(c), isAsterisk(false) {}

  char c;
  bool isAsterisk;
};

class Solution {
public:
  std::vector<Token> tokens_;
  std::string s_;
  std::unordered_map<int, std::unordered_map<int, int>> cache_;

  bool isMatch(string s, string p) {
    for (auto c : p) {
      if (c == '*') {
        tokens_.back().isAsterisk = true;
      } else {
        tokens_.push_back(Token{c});
      }
    }
    s_ = s;

    return match(0, 0, s_.size(), tokens_.size());
  }

  bool cache_match(int s_start, int t_start, int s_length, int t_length) {
    auto cache = cache_[s_start][t_start];
    if (cache < 0) {
      return false;
    } else if (cache > 0) {
      return true;
    } else {
      auto result = match(s_start, t_start, s_length, t_length);
      cache_[s_start][t_start] = result;
      return result;
    }
  }

  bool match(int s_start, int t_start, int s_length, int t_length) {
    if (t_start == t_length)
      return s_start == s_length;

    const auto &token = tokens_[t_start];
    if (token.isAsterisk) {
      if (cache_match(s_start, t_start + 1, s_length, t_length)) {
        return true;
      }

      int s_index = s_start;
      while (s_index < s_length) {
        if (token.c == '.') {
          if (cache_match(s_index + 1, t_start + 1, s_length, t_length))
            return true;
        } else if (token.c == s_[s_index]) {
          if (cache_match(s_index + 1, t_start + 1, s_length, t_length))
            return true;
        } else {
          break;
        }
        s_index++;
      }

      return false;
    } else {
      if (token.c == '.') {
        return cache_match(s_start + 1, t_start + 1, s_length, t_length);
      } else {
        if (token.c == s_[s_start]) {
          return cache_match(s_start + 1, t_start + 1, s_length, t_length);
        } else {
          return false;
        }
      }
    }
  }
};
