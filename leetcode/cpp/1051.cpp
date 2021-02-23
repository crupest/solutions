#include <vector>

using std::vector;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> height_counter(101);
        for (int height : heights)
        {
            height_counter[height]++;
        }

        auto iter = heights.cbegin();

        int result = 0;

        for (int height = 1; height <= 100; height++)
        {
            int height_count = height_counter[height];
            while (height_count > 0)
            {
                if (*iter++ != height)
                    result++;
                --height_count;
            }
        }

        return result;
    }
};