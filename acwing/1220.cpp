#include <iostream>
#include <vector>

const int N = 100010;

struct Node {
  int w;
  std::vector<int> children;
};

int n;
Node nodes[N];
bool visited[N];
long long contain_root[N];
long long contain_or_not_contain_root[N];

void dfs(int i) {
  visited[i] = true;
  long long this_contain_root = nodes[i].w;
  long long this_contain_or_not_contain_root = nodes[i].w;

  for (auto next : nodes[i].children) {
    if (!visited[next]) {
      dfs(next);
      if (contain_root[next] > 0) {
        this_contain_root += contain_root[next];
      }
      if (contain_or_not_contain_root[next] >
          this_contain_or_not_contain_root) {
        this_contain_or_not_contain_root = contain_or_not_contain_root[next];
      }
    }
  }

  if (this_contain_root > this_contain_or_not_contain_root) {
    this_contain_or_not_contain_root = this_contain_root;
  }

  contain_root[i] = this_contain_root;
  contain_or_not_contain_root[i] = this_contain_or_not_contain_root;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    std::cin >> nodes[i].w;
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    nodes[a].children.push_back(b);
    nodes[b].children.push_back(a);
  }

  dfs(1);

  std::cout << contain_or_not_contain_root[1];

  return 0;
}
