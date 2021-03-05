#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int result = n;

  while (n >= 3) {
    int exchange = n / 3;
    int rest = n % 3;
    result += exchange;
    n = exchange + rest;
  }

  std::cout << result;

  return 0;
}
