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

        if (count == 1)
            return nums.front();

        int not_rob_prev = 0;
        int rob_prev = nums.front();
        int not_rob_prev_and_not_rob_first = 0;
        int rob_prev_and_not_rob_first = 0;

        for (int i = 1; i < count - 1; i++)
        {
            int not_rob_prev_cache = not_rob_prev;
            int not_rob_prev_and_not_rob_first_cache = not_rob_prev_and_not_rob_first;
            not_rob_prev = std::max(not_rob_prev_cache, rob_prev);
            rob_prev = std::max(not_rob_prev_cache + nums[i], not_rob_prev);
            not_rob_prev_and_not_rob_first = std::max(not_rob_prev_and_not_rob_first_cache, rob_prev_and_not_rob_first);
            rob_prev_and_not_rob_first = std::max(not_rob_prev_and_not_rob_first_cache + nums[i], not_rob_prev_and_not_rob_first);
        }

        // last houst
        {
            int not_rob_prev_and_not_rob_first_cache = not_rob_prev_and_not_rob_first;
            not_rob_prev_and_not_rob_first = std::max(not_rob_prev_and_not_rob_first_cache, rob_prev_and_not_rob_first);
            rob_prev_and_not_rob_first = std::max(not_rob_prev_and_not_rob_first_cache + nums[count - 1], not_rob_prev_and_not_rob_first);
        }

        return std::max(rob_prev, rob_prev_and_not_rob_first);
    }
};
