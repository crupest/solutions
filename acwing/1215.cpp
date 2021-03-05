#include <cstring>
#include <iostream>

const int MAX = 1000010; // Why 1000001 is not ok!?

int n;
int H[100001];
int bit[MAX];
int reverse_pairs[100001];

int lowbit(int x) { return x & -x; }

void add(int x, int y) {
  for (int i = x; i < MAX; i += lowbit(i)) {
    bit[i] += y;
  }
}

int query(int x) {
  int result = 0;
  for (int i = x; i != 0; i -= lowbit(i)) {
    result += bit[i];
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    std::cin >> H[i];
    H[i]++;
  }

  for (int i = 1; i <= n; i++) {
    add(H[i], 1);
    reverse_pairs[i] = i - query(H[i]);
  }

  std::memset(bit, 0, sizeof bit);

  for (int i = n; i >= 1; i--) {
    add(H[i], 1);
    reverse_pairs[i] += query(H[i] - 1);
  }

  long long result = 0;

  for (int i = 1; i <= n; i++) {
    result += (1LL + reverse_pairs[i]) * reverse_pairs[i] / 2;
  }

  std::cout << result;

  return 0;
}
