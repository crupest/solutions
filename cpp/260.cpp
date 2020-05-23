#include <vector>
#include <unordered_set>

using std::vector;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        std::unordered_set<int> s;
        for (auto i : nums)
        {
            const auto result = s.find(i);
            if (result == s.cend())
                s.insert(i);
            else
                s.erase(result);
        }

        return vector<int>(s.cbegin(), s.cend());
    }
};
