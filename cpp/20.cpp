#include <string>

using std::string;

#include <stack>

class Solution
{
public:
    inline static char get_companion(char c)
    {
        switch (c)
        {
        case ')':
            return '(';
        case ']':
            return '[';
        default:
            return '{';
        }
    }

    bool isValid(string s)
    {
        std::stack<char> stack;

        for (const auto c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
            {
                stack.push(c);
                break;
            }
            case ')':
            case ']':
            default:
            {
                if (stack.empty())
                    return false;
                const auto top = stack.top();
                const char companion = get_companion(c);
                if (top != companion)
                    return false;
                stack.pop();
            }
            }
        }

        return stack.empty();
    }
};
