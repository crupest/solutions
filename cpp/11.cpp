#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        auto left = height.cbegin();
        auto right = height.cend();
        --right;

        int result = 0;

        // although length could be calculated by right - left,
        // but this can be cached in register.
        int length = height.size() - 1;

        while (left != right)
        {
            const int left_v = *left;
            const int right_v = *right;
            const int capacity = std::min(left_v, right_v) * length;
            result = std::max(capacity, result);

            if (left_v < right_v)
            {
                ++left;
            }
            else
            {
                --right;
            }

            length--;
        }

        return result;
    }
};
