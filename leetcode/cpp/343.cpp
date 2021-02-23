#include <cmath>

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        if (n % 3 == 1)
        {
            return static_cast<int>(std::pow(3, n / 3 - 1)) * 4;
        }
        else if (n % 3 == 2)
        {
            return static_cast<int>(std::pow(3, n / 3)) * 2;
        }
        return static_cast<int>(std::pow(3, n / 3));
    }
};
