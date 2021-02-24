#include <algorithm>
#include <iostream>

int N, V;
int v[1001];
int w[1001];
int s[1001];
int states[2001];

void CompletePack(int v, int w) {
  for (int j = v; j <= V; j++) {
    states[j] = std::max(states[j], states[j - v] + w);
  }
}

void ZeroOnePack(int v, int w) {
  for (int j = V; j >= v; j--) {
    states[j] = std::max(states[j], states[j - v] + w);
  }
}

int main() {
  std::cin >> N >> V;

  for (int i = 1; i <= N; i++) {
    std::cin >> v[i] >> w[i] >> s[i];
  }

  for (int i = 1; i <= N; i++) {
    if (v[i] * s[i] >= V) {
      CompletePack(v[i], w[i]);
    } else {
      int k = 1;
      int amount = s[i];

      while (k < amount) {
        ZeroOnePack(k * v[i], k * w[i]);
        amount -= k;
        k *= 2;
      }

      if (amount != 0) {
        ZeroOnePack(amount * v[i], amount * w[i]);
      }
    }
  }

  std::cout << states[V];

  return 0;
}
