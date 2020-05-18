#include <vector>

using std::vector;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        auto iter_head = nums.cbegin();
        auto iter = iter_head + 1;
        int current = nums.front();
        int count = 1;

        while (iter != nums.cend())
        {
            const auto v = *iter;
            if (v == current)
            {
                nums.erase(iter);
                iter = iter_head + 1;
            }
            else
            {
                current = v;
                count++;
                iter_head = iter;
                ++iter;
            }
        }

        return count;
    }
};
