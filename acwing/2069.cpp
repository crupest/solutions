#include <iostream>
#include <vector>

struct Node {
  int m = 0;
  Node *set;
  Node *left = nullptr;
  Node *right = nullptr;

  Node() : set(this) {}

  void SetParent(Node *parent, bool l) {
    set = parent;
    l ? parent->left = this : parent->right = this;
  }

  Node *GetSetRepresentative() {
    Node *r = this;
    while (r->set != r) {
      r = r->set;
    }
    set = r;
    return set;
  }

  bool has_dfs = false;

  void Dfs() {
    if (has_dfs)
      return;
    has_dfs = true;
    if (left != nullptr)
      left->Dfs(m);
    if (right != nullptr)
      right->Dfs(m);
  }

  void Dfs(int c) {
    m += c;
    if (left != nullptr)
      left->Dfs(m);
    if (right != nullptr)
      right->Dfs(m);
  }
};

Node nodes[10010];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;

  std::cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int operation, a, b;
    std::cin >> operation >> a >> b;

    if (operation == 1) {
      auto ra = nodes[a].GetSetRepresentative(),
           rb = nodes[b].GetSetRepresentative();

      if (ra != rb) {
        auto node = new Node;
        ra->SetParent(node, true);
        rb->SetParent(node, false);
      }
    } else {
      nodes[a].GetSetRepresentative()->m += b;
    }
  }

  for (int i = 1; i <= n; i++) {
    auto &node = nodes[i];
    node.GetSetRepresentative()->Dfs();
    std::cout << node.m << ' ';
  }

  return 0;
}
