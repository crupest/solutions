#include <algorithm>
#include <iostream>

int N, V;
int v[1001];
int w[1001];
int states[1001][1001];

int main() {
  std::cin >> N >> V;

  for (int i = 1; i <= N; i++) {
    std::cin >> v[i] >> w[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = V; j >= 0; j--) {
      if (j >= v[i]) {
        states[i][j] =
            std::max(states[i - 1][j], states[i - 1][j - v[i]] + w[i]);
      } else {
        states[i][j] = states[i - 1][j];
      }
    }
  }

  std::cout << states[N][V];

  return 0;
}
