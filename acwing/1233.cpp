#include <iostream>
#include <utility>

const int M = 1010;

int N;
char map[M][M];
bool visited[M][M];

int not_sink_count;

const std::pair<int, int> moves[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int r, int c) {
  if (visited[r][c])
    return;
  if (map[r][c] != '#')
    return;

  visited[r][c] = true;

  bool sink = false;

  for (const auto &move : moves) {
    if (map[r + move.first][c + move.second] == '.') {
      sink = true;
      break;
    }
  }

  if (!sink) {
    not_sink_count++;
  }

  for (const auto &move : moves) {
    dfs(r + move.first, c + move.second);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> map[i][j];
    }
  }

  int result = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (map[i][j] == '#' && !visited[i][j]) {
        dfs(i, j);
        if (not_sink_count == 0) {
          result++;
        }
        not_sink_count = 0;
      }
    }
  }

  std::cout << result;

  return 0;
}
