#include <vector>

using std::vector;

class NumArray
{
private:
    vector<int> prefix_sums;

public:
    NumArray(vector<int> &nums)
    {
        prefix_sums.push_back(0);
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
            prefix_sums.push_back(sum);
        }
    }

    int sumRange(int i, int j)
    {
        return prefix_sums[j + 1] - prefix_sums[i];
    }
};
