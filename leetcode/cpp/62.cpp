#include <utility>

class Solution
{
public:
    // C(m + n - 2, m - 1)
    int uniquePaths(int m, int n)
    {
        if (m < n)
            std::swap(m, n);

        long long result = 1;
        for (int i = m; i <= m + n - 2; i++)
        {
            result *= i;
        }

        for (int i = 2; i <= n - 1; i++)
        {
            result /= i;
        }

        return result;
    }
};
