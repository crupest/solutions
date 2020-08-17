#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    static void backtrack(vector<string> &result, string &current, int left, int right, int count, int string_length)
    {
        if (current.length() == string_length)
        {
            result.push_back(current);
            return;
        }

        if (left < count)
        {
            current.push_back('(');
            backtrack(result, current, left + 1, right, count, string_length);
            current.pop_back();
        }

        if (right < left)
        {
            current.push_back(')');
            backtrack(result, current, left, right + 1, count, string_length);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n, n * 2);
        return std::move(result);
    }
};