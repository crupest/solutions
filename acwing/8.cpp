#include <algorithm>
#include <iostream>

int N, V, M;
int v[1001];
int w[1001];
int m[1001];
int states[101][101];

int main() {
  std::cin >> N >> V >> M;

  for (int i = 1; i <= N; i++) {
    std::cin >> v[i] >> m[i] >> w[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = V; j >= v[i]; j--) {
      for (int k = M; k >= m[i]; k--) {
        states[j][k] =
            std::max(states[j][k], states[j - v[i]][k - m[i]] + w[i]);
      }
    }
  }

  std::cout << states[V][M];

  return 0;
}