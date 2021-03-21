#include <iostream>
#include <map>
#include <set>

const int M = 100010;

int N, D, K;

std::map<int, std::multiset<int>> vote_map;

bool check(const std::multiset<int> &v) {
  auto iter1 = v.cbegin();
  auto iter2 = v.cbegin();

  const auto end = v.cend();

  int count = 1;

  while (iter2 != end) {
    while (*iter2 - *iter1 >= D) {
      ++iter1;
      count--;
    }

    if (count >= K)
      return true;

    ++iter2;
    count++;
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> D >> K;

  for (int i = 1; i <= N; i++) {
    int ts, id;
    std::cin >> ts >> id;
    vote_map[id].insert(ts);
  }

  int result;

  for (const auto &vote : vote_map) {
    if (check(vote.second)) {
      std::cout << vote.first << "\n";
    }
  }

  return 0;
}
