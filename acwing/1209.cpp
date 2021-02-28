#include <array>
#include <iostream>
#include <vector>

int number;
int count = 0;
std::array<bool, 10> used{false};
std::array<int, 9> current;

int calc(int start, int end) {
  int n = 0;
  for (int i = start; i < end; i++) {
    n *= 10;
    n += current[i];
  }
  return n;
}

void dfs(int n) {
  if (n == 9) {
    for (int i = 1; i <= 7; i++)
      for (int j = i + 1; j <= 8; j++) {
        int a = calc(0, i);
        int b = calc(i, j);
        int c = calc(j, 9);
        if ((number - a) * b == c) {
          count++;
        }
      }
    return;
  }

  for (int i = 1; i <= 9; i++) {
    if (!used[i]) {
      used[i] = true;
      current[n] = i;
      dfs(n + 1);
      used[i] = false;
    }
  }
}

int main() {
  std::cin >> number;
  dfs(0);
  std::cout << count;
  return 0;
}
