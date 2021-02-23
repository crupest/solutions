#include <bitset>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        std::bitset<sizeof(n) * 8> bits(n);
        return bits.count() == 1;
    }
};
