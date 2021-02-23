#include <string>

using std::string;

int romanDigitNumber(char romanDigit)
{
    switch (romanDigit)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    };
    return 0;
}

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;

        int count = s.size();

        for (int i = 0; i < count; i++)
        {
            const char c = s[i];
            int num = romanDigitNumber(c);
            if (i < count - 1)
            {
                const char next = s[i + 1];
                if ((c == 'I' && (next == 'V' || next == 'X')) || (c == 'X' && (next == 'L' || next == 'C')) || (c == 'C') && (next == 'D' || next == 'M'))
                {
                    num = -num;
                }
            }

            result += num;
        }

        return result;
    }
};
