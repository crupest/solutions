#include <algorithm>
#include <iostream>

int N, V;
int v[1001];
int w[1001];
int s[1001];
int states[1001];

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

void MultiplePack(int v, int w, int s) {
  int k = 1;

  while (k < s) {
    ZeroOnePack(k * v, k * w);
    s -= k;
    k *= 2;
  }

  ZeroOnePack(s * v, s * w);
}

int main() {
  std::cin >> N >> V;

  for (int i = 1; i <= N; i++) {
    std::cin >> v[i] >> w[i] >> s[i];
  }

  for (int i = 1; i <= N; i++) {
    if (s[i] < 0) {
      ZeroOnePack(v[i], w[i]);
    } else if (s[i] == 0) {
      CompletePack(v[i], w[i]);
    } else {
      MultiplePack(v[i], w[i], s[i]);
    }
  }

  std::cout << states[V];

  return 0;
}
