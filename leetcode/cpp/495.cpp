#include <vector>

using std::vector;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.empty())
            return 0;

        int total_time = 0;

        int start_time = timeSeries.front();
        int expected_end_time = start_time + duration;

        for (auto iter = timeSeries.cbegin() + 1; iter != timeSeries.cend(); ++iter)
        {
            const auto this_time = *iter;
            if (this_time <= expected_end_time)
            {
                expected_end_time = this_time + duration;
            }
            else
            {
                total_time += expected_end_time - start_time;
                start_time = this_time;
                expected_end_time = this_time + duration;
            }
        }

        total_time += expected_end_time - start_time;

        return total_time;
    }
};