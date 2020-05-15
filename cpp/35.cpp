#include <vector>

using std::vector;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;

        int left_index = 0;
        int right_index = nums.size();

        while (left_index != right_index)
        {
            const int middle_index = (left_index + right_index) / 2;
            const int middle_value = nums[middle_index];
            if (target < middle_value)
            {
                right_index = middle_index;
            }
            else if (target > middle_value)
            {
                left_index = middle_index + 1;
            }
            else
            {
                return middle_index;
            }
        }

        return left_index;
    }
};
