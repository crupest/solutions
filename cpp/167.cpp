#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (true)
        {
            const auto sum = numbers[left] + numbers[right];
            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                return {left + 1, right + 1};
            }
        }
    }
};
