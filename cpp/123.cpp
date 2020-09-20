#include <vector>
#include <iostream>
using std::vector;

#include <algorithm>

class Solution
{
public:
    // 0 -> after buy for the first time
    // 1 -> after sell for the first time
    // 2 -> after buy for the second time
    // 3 -> after sell for the second time

    int maxProfit(vector<int> &prices)
    {
        int day_count = prices.size();

        int state_0 = -prices[0];
        int state_1 = 0;
        int state_2 = -prices[0];
        int state_3 = 0;

        for (int day = 1; day < day_count; day++)
        {
            state_0 = std::max(state_0, -prices[day]);
            state_1 = std::max(state_1, state_0 + prices[day]);
            state_2 = std::max(state_2, state_1 - prices[day]);
            state_3 = std::max(state_3, state_2 + prices[day]);
        }

        return std::max({state_0, state_1, state_2, state_3});
    }
};
