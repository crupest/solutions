#include <vector>

using std::vector;

#include <algorithm>

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max = 0;
        const int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (i <= max)
            {
                max = std::max(max, i + nums[i]);
                if (max >= size - 1)
                    return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};