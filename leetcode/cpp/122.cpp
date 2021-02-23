#include <vector>

using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;

        int day_count = prices.size();

        vector<vector<int>> dp(day_count, std::vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < day_count; i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[day_count - 1][0];
    }
};
