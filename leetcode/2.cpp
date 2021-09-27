#include <algorithm>
#include <iostream>
#include <set>
#include <queue>

using std::vector;

struct P {
  int x;
  int y;
};

struct I {
  int x;
  int y;
  int v;
};

P mm[]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
  vector<vector<int>> bicycleYard(vector<int> &position,
                                  vector<vector<int>> &terrain,
                                  vector<vector<int>> &obstacle) {
    std::vector<std::vector<std::set<int>>> visited(
        terrain.size(), std::vector<std::set<int>>(terrain.front().size()));

    std::queue<I> q{{position[0], position[1], 1}};

    bool f = false;

    while (true) {
      if (f && q.size() == 1) {
        break;
      }
      f = true;

      I b = q.back();
      q.pop_back();

      if (b.v <= 0 || visited[b.x][b.y].count(b.v)) {

      }

      visited[b.x][b.y].insert(v);

      for (auto p : mm) {
        int nx = x + p.x, ny = y + p.y;
        if (nx >= 0 && nx < terrain.size() && ny >= 0 &&
            ny < terrain.front().size()) {
          DFS(v + terrain[x][y] - terrain[nx][ny] - obstacle[nx][ny], nx, ny,
              terrain, obstacle, visited);
        }
      }
    }

    vector<vector<int>> result;

    for (int i = 0; i < terrain.size(); i++) {
      for (int j = 0; j < obstacle.size(); j++) {
        if ((i != position[0] || j != position[1]) && visited[i][j].count(1)) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
};