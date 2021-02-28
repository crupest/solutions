#include <cmath>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  int fever_ant;
  std::cin >> fever_ant;

  int fever_position = std::abs(fever_ant);

  int left = 0, right = 0;

  for (int i = 1; i < n; i++) {
    int ant;
    std::cin >> ant;
    int position = std::abs(ant);
    if (position < fever_position && ant > 0) {
      left++;
    }
    if (position > fever_position && ant < 0) {
      right++;
    }
  }

  if (fever_ant < 0 && left == 0) {
    std::cout << 1;
  } else if (fever_ant > 0 && right == 0) {
    std::cout << 1;
  } else {
    std::cout << left + right + 1;
  }

  return 0;
}
