#include <string>
#include <vector>

using std::string;
using std::vector;

vector<char> c_map[9]{
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}};

void combine(const string::const_iterator &current, const string::const_iterator &end, string &head, vector<string> &result)
{
    const auto &chars = c_map[(*current) - '2'];

    if (current == end)
    {
        for (auto c : chars)
        {
            head.push_back(c);
            result.push_back(head);
            head.pop_back();
        }
        return;
    }

    for (auto c : chars)
    {
        head.push_back(c);
        combine(current + 1, end, head, result);
        head.pop_back();
    }
}

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<string> result;

        if (digits.empty())
            return result;

        std::string head;

        combine(digits.cbegin(), digits.cend() - 1, head, result);

        return result;
    }
};
