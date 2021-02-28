#include <iostream>

int N;
int seq[10000];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> seq[i];
  }

  int count = N;

  for (int start = 0; start < N; start++) {
    int min = seq[start], max = seq[start];

    for (int end = start + 1; end < N; end++) {
      int current = seq[end];

      if (current > max) {
        max = current;
      }

      if (current < min) {
        min = current;
      }

      if (max - min == end - start) {
        count++;
      }
    }
  }

  std::cout << count;

  return 0;
}
