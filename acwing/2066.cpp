#include <cctype>
#include <iostream>

int main() {
  std::string input;
  std::cin >> input;
  std::string result;

  for (int i = 0; i < input.size(); i++) {
    if (std::isalpha(input[i])) {
      result.push_back(input[i]);
    } else {
      int c = input[i] - '1';
      result.append(c, input[i - 1]);
    }
  }

  std::cout << result;

  return 0;
}
