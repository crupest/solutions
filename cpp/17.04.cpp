#include <vector>

using std::vector;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        const int size = nums.size();
        const int sum = size * (size + 1) / 2;

        int real_sum = 0;
        for (auto i : nums)
        {
            real_sum += i;
        }

        return sum - real_sum;
    }
};
