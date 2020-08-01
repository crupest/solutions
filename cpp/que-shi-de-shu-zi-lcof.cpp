#include <vector>

using std::vector;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        if (nums.back() == nums.size() - 1)
            return nums.size();

        int low = 0, high = nums.size() - 1;
        while (low != high)
        {
            int middle = (low + high) / 2;
            if (middle == nums[middle])
            {
                low = middle + 1;
            }
            else
            {
                high = middle;
            }
        }

        return low;
    }
};
