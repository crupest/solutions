#include <cmath>
#include <iostream>

int w, m, n;

int row(int x) { return (x - 1) / w; }

int col(int x, int r) {
  int result = (x - 1) % w;
  if (r % 2) {
    result = w - 1 - result;
  }
  return result;
}

int main() {
  std::cin >> w >> m >> n;
  int m_r = row(m);
  int m_c = col(m, m_r);
  int n_r = row(n);
  int n_c = col(n, n_r);

  std::cout << std::abs(m_r - n_r) + std::abs(m_c - n_c);

  return 0;
}
