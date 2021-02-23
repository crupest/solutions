#include <vector>

using std::vector;

inline int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 1)
            return 0;

        // odd
        int result_odd = 0;
        for (int i = 0; i < size; i += 2)
        {
            int neighber = 1001;
            if (i - 1 >= 0)
                neighber = min(neighber, nums[i - 1]);
            if (i + 1 < size)
                neighber = min(neighber, nums[i + 1]);
            if (nums[i] >= neighber)
                result_odd += nums[i] - neighber + 1;
        }

        // even
        int result_even = 0;
        for (int i = 1; i < size; i += 2)
        {
            int neighber = 1001;
            if (i - 1 >= 0)
                neighber = min(neighber, nums[i - 1]);
            if (i + 1 < size)
                neighber = min(neighber, nums[i + 1]);
            if (nums[i] >= neighber)
                result_even += nums[i] - neighber + 1;
        }

        return min(result_odd, result_even);
    }
};
