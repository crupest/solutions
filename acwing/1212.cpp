#include <iostream>

int n, m, k;
int v[51][51];
int f[51][51][14][14]; // row col count max
const int MOD = 1000000007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m >> k;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      std::cin >> v[i][j];
      v[i][j]++;
    }

  f[1][1][0][0] = 1;
  f[1][1][1][v[1][1]] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int c = 0; c <= k; c++) {
        for (int m = 0; m <= 13; m++) {
          f[i][j][c][m] = (f[i][j][c][m] + f[i][j - 1][c][m]) % MOD;
          f[i][j][c][m] = (f[i][j][c][m] + f[i - 1][j][c][m]) % MOD;

          if (c && v[i][j] == m) {
            for (int max = 0; max < v[i][j]; max++) {
              f[i][j][c][m] = (f[i][j][c][m] + f[i][j - 1][c - 1][max]) % MOD;
              f[i][j][c][m] = (f[i][j][c][m] + f[i - 1][j][c - 1][max]) % MOD;
            }
          }
        }
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= 13; i++)
    result = (result + f[n][m][k][i]) % MOD;

  std::cout << result;

  return 0;
}
