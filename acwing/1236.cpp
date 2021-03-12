#include <iostream>

const int MAX = 100000;
const int MM = 100010;

int N;

long long ca[MM];
long long cb[MM];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;
    ca[a]++;
  }

  for (int n = 1; n <= MAX; n++) {
    ca[n] = ca[n - 1] + ca[n];
  }

  for (int i = 0; i < N; i++) {
    int b;
    std::cin >> b;
    cb[b]++;
  }

  for (int n = 1; n <= MAX; n++) {
    cb[n] *= ca[n - 1];
  }

  for (int n = 2; n <= MAX; n++) {
    cb[n] = cb[n - 1] + cb[n];
  }

  long long result = 0;

  for (int i = 0; i < N; i++) {
    int c;
    std::cin >> c;
    if (c >= 2) {
      result += cb[c - 1];
    }
  }

  std::cout << result;

  return 0;
}
