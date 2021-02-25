#include <ios>
#include <iostream>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);

  int repeat;

  int n;
  std::cin >> n;

  std::set<int> ids;

  while (std::cin >> n) {
    auto result = ids.insert(n);
    if (!result.second)
      repeat = n;
  }

  auto iter = ids.cbegin();

  int last = *iter++;

  while (++last == *iter++)
    ;

  std::cout << last << ' ' << repeat;

  return 0;
}
