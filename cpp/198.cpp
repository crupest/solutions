#include <vector>

using std::vector;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int count = nums.size();
        if (count == 0)
            return 0;

        int not_rob_prev = 0;
        int rob_prev = nums.front();

        for (int i = 1; i < count; i++)
        {
            int not_rob_prev_cache = not_rob_prev;
            not_rob_prev = std::max(not_rob_prev_cache, rob_prev);
            rob_prev = std::max(not_rob_prev_cache + nums[i], not_rob_prev);
        }

        return rob_prev;
    }
};
