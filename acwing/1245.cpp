#include <iostream>

bool check(int n) {
  while (n != 0) {
    int k = n % 10;
    if (k == 2 || k == 0 || k == 1 || k == 9) {
      return true;
    }
    n /= 10;
  }
  return false;
}

int main() {
  int n;
  std::cin >> n;

  long long sum;

  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      sum += i;
    }
  }

  std::cout << sum;

  return 0;
}
