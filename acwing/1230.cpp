#include <iostream>

using ll = long long;

const int M = 100010;

int N, K;
ll p;
int c[M];
ll result;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> K;

  c[0] = 1;

  for (int i = 1; i <= N; i++) {
    int a;
    std::cin >> a;

    p += a;

    int r = p % K;

    result += c[r];

    c[r]++;
  }

  std::cout << result;

  return 0;
}
