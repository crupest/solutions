#include <vector>

using std::vector;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        const auto end = arr.cend();
        auto iter = arr.cbegin();
        auto last_iter = arr.cbegin();

        double sum = 0;

        int result = 0;

        for (int i = 0; i < k; i++)
        {
            sum += *iter++;
        }

        while (iter != end)
        {
            if (sum / k >= threshold)
            {
                result++;
            }
            sum -= *last_iter++;
            sum += *iter++;
        }

        if (sum / k >= threshold)
        {
            result++;
        }

        return result;
    }
};
