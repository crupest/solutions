#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int current_count = 0;
  int current_level_count = 1;
  int current_level = 1;
  long long current_sum = 0;
  long long max_sum = -1000000;
  int result = 1;

  for (int i = 0; i < n; i++) {
    long long a;
    std::cin >> a;
    current_sum += a;
    current_count++;

    if (current_count == current_level_count) {
      if (current_sum > max_sum) {
        max_sum = current_sum;
        result = current_level;
      }
      current_count = 0;
      current_level_count *= 2;
      current_sum = 0;
      current_level++;
    }
  }

  if (current_count && current_sum > max_sum) {
    result = current_level;
  }

  std::cout << result;

  return 0;
}
