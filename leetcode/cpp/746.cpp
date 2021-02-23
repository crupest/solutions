#include <vector>

using std::vector;

#include <algorithm>

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int count = cost.size();

        // Total cost for index i means min cost of stepping through the number i stair,
        // after which you are free to jump two or one stair.
        // total_costs[i] is based on total_costs[i - 2] and total_costs[i - 1].
        // Note:
        // This is not min cost to step above the number i stair, which has no simple dependency
        // relationship because based on whether it steps through the last step there are two situation.
        // However with the restriction of stepping through that last stair, there is a
        // dependency relationship. And we can easily get the final result by comparing total_costs[count - 2]
        // and total_costs[count - 1]. But not just use total_costs[count - 1].
        vector<int> total_costs(count);

        total_costs[0] = cost[0];
        total_costs[1] = cost[1];

        for (int i = 2; i < count; i++)
        {
            total_costs[i] = std::min(total_costs[i - 2], total_costs[i - 1]) + cost[i];
        }

        return std::min(total_costs[count - 2], total_costs[count - 1]);
    }
};
