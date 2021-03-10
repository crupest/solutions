#include <iostream>
#include <utility>

int N;
int x[10010];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> x[i];
  }

  int result = 0;

  for (int i = 1; i <= N - 1; i++) {
    if (x[i] != i) {
      for (int j = i + 1; j <= N; j++) {
        if (x[j] == i) {
          x[j] = x[i];
          result++;
          break;
        }
      }
    }
  }

  std::cout << result;

  return 0;
}
