#include <vector>

using std::vector;

#include <algorithm>
#include <functional>

class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        std::sort(A.begin(), A.end(), std::greater<int>{});
        for (int i = 0; i < A.size() - 2; i++)
        {
            if (A[i] < A[i + 1] + A[i + 2])
            {
                return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }
};
