#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> result;
        result.resize(nums.size());
        auto iter = result.begin();
        auto iter1 = nums.cbegin();
        auto iter2 = nums.cbegin() + n;
        for (int i = 0; i < n; i++)
        {
            *iter++ = *iter1++;
            *iter++ = *iter2++;
        }

        return std::move(result);
    }
};
