#include <string>

using std::string;

bool strict_palindrome(string::const_iterator left, string::const_iterator right)
{
    while (left < right)
    {
        if (*left != *right)
            return false;
        ++left;
        --right;
    }
    return true;
}

class Solution
{
public:
    bool validPalindrome(string s)
    {
        string::const_iterator left = s.cbegin();
        string::const_iterator right = s.cend() - 1;

        while (left < right)
        {
            if (*left != *right)
                return strict_palindrome(left, right - 1) || strict_palindrome(left + 1, right);

            ++left;
            --right;
        }
        return true;
    }
};
