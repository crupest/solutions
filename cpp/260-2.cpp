#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int diff = 0;
        for (auto i : nums)
        {
            diff ^= i;
        }

        int mask = diff & (-diff);

        int result = 0;
        for (auto i : nums)
        {
            result ^= (i & mask) ? i : 0;
        }

        return {result, result ^ diff};
    }
};
