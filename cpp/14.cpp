#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string result;

        const auto &first = strs.front();

        for (int i = 0; i < first.size(); i++)
        {
            char c = first[i];

            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != c)
                    goto r;
            }

            result.push_back(c);
        }

    r:
        return result;
    }
};
