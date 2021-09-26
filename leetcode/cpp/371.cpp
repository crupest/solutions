
class Solution {
public:
  int getSum(int a, int b) {
    unsigned x = a, y = b;

    unsigned carry = 0;

    unsigned result = 0;

    for (int i = 0; i < sizeof(int) * 8; i++) {
      unsigned mask = 1 << i;

      unsigned n = x & mask ? 1 : 0, m = y & mask ? 1 : 0;

      if (n ^ m ^ carry) {
        result |= mask;
      }

      carry = n & m || n & carry || m & carry;
    }

    return static_cast<int>(result);
  }
};
