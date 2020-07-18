#include <string>
#include <cctype>
#include <utility>

using std::string;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        if (s.empty())
            return s;

        auto front = s.rend();
        auto back = s.end();

        bool move_front = true;
        while (true)
        {
            if (move_front)
            {
                if (std::isalpha(*--front))
                {
                    move_front = false;
                }
            }
            else
            {
                if (std::isalpha(*--back))
                {
                    std::swap(*front, *back);
                    move_front = true;
                }
            }

            if (front.base() == back)
            {
                break;
            }
        }

        return s;
    }
};
