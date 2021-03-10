#include <iostream>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int N;
int A[110];

const int M = 10000;

bool f[M + 10];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
  }

  int a = A[1];

  for (int i = 2; i <= N; i++) {
    a = gcd(a, A[i]);
  }

  if (a != 1) {
    std::cout << "INF";
    return 0;
  }

  f[0] = true;

  for (int i = 1; i <= N; i++) {
    for (int w = A[i]; w <= M; w++) {
      f[w] = f[w] || f[w - A[i]];
    }
  }

  int count = 0;

  for (int i = 1; i <= M; i++) {
    if (f[i] == false)
      count++;
  }

  std::cout << count;

  return 0;
}
