#include <cstring>
#include <iostream>

const int MOD = 1e9 + 7;

int n, m;
bool conflict_matrix[7][7];

long long f[7];
long long temp[7];

int back(int x) {
  switch (x) {
  case 1:
    return 4;
  case 2:
    return 5;
  case 3:
    return 6;
  case 4:
    return 1;
  case 5:
    return 2;
  case 6:
    return 3;
  default:
    return 0;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    conflict_matrix[a][b] = true;
    conflict_matrix[b][a] = true;
  }

  for (int i = 1; i <= 6; i++)
    f[i] = 4;

  for (int c = 2; c <= n; c++) {
    for (int up = 1; up <= 6; up++) {
      for (int down = 1; down <= 6; down++) {
        if (!conflict_matrix[back(down)][up]) {
          temp[up] = (temp[up] + f[down] * 4) % MOD;
        }
      }
    }
    std::memcpy(f, temp, sizeof f);
    std::memset(temp, 0, sizeof temp);
  }

  long long result = 0;
  for (int i = 1; i <= 6; i++) {
    result = (result + f[i]) % MOD;
  }

  std::cout << result;

  return 0;
}
