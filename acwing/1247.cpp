#include <cmath>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  long long result = 0;

  long long min = 1e9 + 1;
  long long max = -1e9 - 1;

  for (int i = 0; i < N + M + 1; i++) {
    long long a;
    std::cin >> a;
    max = std::max(a, max);
    min = std::min(a, min);
    if (M == 0) {
      result += a;
    } else {
      result += std::abs(a);
    }
  }

  if (M != 0 && max < 0) {
    result += 2 * max;
  }

  if (M == 1 && min > 0) {
    result -= 2 * min;
  }

  std::cout << result;

  return 0;
}
