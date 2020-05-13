#include <vector>

using std::vector;

void combine1(int start, int end, int rest_select_count, vector<int> &head, vector<vector<int>> &result)
{
    if (rest_select_count == 0)
    {
        for (int i = start; i < end; i++)
        {
            head.push_back(i);
            result.push_back(head);
            head.pop_back();
        }
        return;
    }

    for (int i = start; i < end - rest_select_count; i++)
    {
        head.push_back(i);
        combine1(i + 1, end, rest_select_count - 1, head, result);
        head.pop_back();
    }
}

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;

        vector<int> head;
        combine1(1, 1 + n, k - 1, head, result);

        return result;
    }
};

int main()
{
    Solution s;
    auto result = s.combine(20, 16);
    return 0;
}