#include <vector>

using std::vector;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1) return 0;

        int result = 0;
        int min = prices.front();
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - min > result)
                result = prices[i] - min;
            if (prices[i] < min)
                min = prices[i];
        }

        return result;
    }
};
