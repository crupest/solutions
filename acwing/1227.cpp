#include <iostream>

const int M = 1e5 + 10;

int N, K;
int H[M];
int W[M];

bool check(int l) {
  if (l == 0)
    return true;

  int count = 0;

  for (int i = 1; i <= N; i++) {
    count += (H[i] / l) * (W[i] / l);
    if (K <= count) {
      return true;
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    std::cin >> H[i] >> W[i];
  }

  int l = 0, r = M;

  while (l != r) {
    int m = l + ((r - l + 1) / 2);

    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  std::cout << l;

  return 0;
}
