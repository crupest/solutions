#include <string>

using std::string;

class Solution
{
public:
    string sortString(string s)
    {
        int count[26]{0};

        for (auto c : s)
        {
            count[c - 'a']++;
        }

        int total_count = s.size();
        string result;

        while (total_count)
        {
            for (int i = 0; i < 26; i++)
            {
                if (count[i])
                {
                    count[i]--;
                    total_count--;
                    result.push_back(i + 'a');
                }
            }

            for (int i = 25; i >= 0; i--)
            {
                if (count[i])
                {
                    count[i]--;
                    total_count--;
                    result.push_back(i + 'a');
                }
            }
        }

        return result;
    }
};
