#include <string>

using std::string;

#include <queue>

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        std::queue<bool> queue;

        int r_people = 0;
        int d_people = 0;
        int r_ban = 0;
        int d_ban = 0;

        for (auto i = senate.cbegin(); i != senate.cend(); ++i)
        {
            if (*i == 'R')
            {
                r_people += 1;
                queue.push(true);
            }
            else
            {
                d_people += 1;
                queue.push(false);
            }
        }

        while (r_people && d_people)
        {
            bool is_r = queue.front();
            queue.pop();
            if (is_r)
            {
                if (d_ban)
                {
                    r_people -= 1;
                    d_ban -= 1;
                }
                else
                {
                    r_ban += 1;
                    queue.push(is_r);
                }
            }
            else
            {
                if (r_ban)
                {
                    d_people -= 1;
                    r_ban -= 1;
                }
                else
                {
                    d_ban += 1;
                    queue.push(is_r);
                }
            }
        }

        return r_people ? "Radiant" : "Dire";
    }
};
