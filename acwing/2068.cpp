#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

int n, K;
int A[100010];
int c[11][100010];
long long result;

int CalcDigitCount(int n) {
  int c = 0;
  while (n != 0) {
    c++;
    n /= 10;
  }
  return c;
}

void work() {
  for (int i = 0; i < n; i++) {
    result += c[CalcDigitCount(A[i])][(K - A[i] % K) % K];
    // Wrong Code I don't know why!
    // int a = A[i];
    // for (int j = 1; j < 11; j++) {
    //   a *= 10;
    //   a %= K;
    //   c[j][a]++;
    // }
    for (int j = 0, power = 1; j < 11; j++) {
      c[j][power * 1ll * A[i] % K]++;
      power = power * 10 % K;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> K;

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  work();

  std::reverse(A, A + n);
  std::memset(c, 0, sizeof c);

  work();

  std::cout << result;

  return 0;
}
