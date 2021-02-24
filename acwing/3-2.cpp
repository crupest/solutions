#include <algorithm>
#include <iostream>

int N, V;
int v[1001];
int w[1001];
int states[1001];

int main() {
  std::cin >> N >> V;

  for (int i = 1; i <= N; i++) {
    std::cin >> v[i] >> w[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= V; j++) {
      if (j >= v[i]) {
        states[j] = std::max(states[j], states[j - v[i]] + w[i]);
      } else {
        states[j] = states[j];
      }
    }
  }

  std::cout << states[V];

  return 0;
}
