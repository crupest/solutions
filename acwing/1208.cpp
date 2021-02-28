#include <iostream>
#include <string>

inline void toggle(char &c) { c = c == '*' ? 'o' : '*'; }

int main() {
  std::string original, expected;
  std::cin >> original >> expected;

  int size = original.size();

  int count = 0;

  for (int i = 0; i < size - 1; i++) {
    if (original[i] != expected[i]) {
      count++;
      toggle(original[i + 1]);
    }
  }

  std::cout << count;

  return 0;
}
