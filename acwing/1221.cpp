#include <cmath>
#include <iostream>

const int M = 5000010;
const int SM = std::sqrt(M / 2);

int s[M];

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i <= SM; i++) {
    const int i2 = i * i;
    const int SMB = M - i2;
    for (int j = i; j * j < SMB; j++) {
      const int a = i2 + j * j;

      if (s[a] == 0) {
        s[a] = i + 1;
      }
    }
  }

  int sm = std::sqrt(n);

  for (int a = 0; a <= sm; a++) {
    int as = a * a;
    int bsm = n - 3 * a * a;
    for (int b = a; b * b <= bsm; b++) {
      int bs = b * b + as;

      int c = s[n - bs];

      if (c != 0) {
        c = c - 1;
        std::cout << a << ' ' << b << ' ' << c << ' '
                  << std::sqrt(n - bs - c * c);
        return 0;
      }
    }
  }

  return 0;
}
