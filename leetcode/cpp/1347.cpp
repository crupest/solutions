#include <string>

using std::string;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int s_count[26]{0};
        int t_count[26]{0};

        for (auto c : s)
        {
            s_count[c - 'a']++;
        }

        for (auto c : t)
        {
            t_count[c - 'a']++;
        }

        int result = 0;

        for (int i = 0; i < 26; i++)
        {
            int a = s_count[i];
            int b = t_count[i];
            if (a > b)
                result += a - b;
        }

        return result;
    }
};