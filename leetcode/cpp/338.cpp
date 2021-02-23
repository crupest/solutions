#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; i++)
        {
            if (i % 2 == 1)
            {
                result[i] = result[i - 1] + 1;
            }
            else
            {
                result[i] = result[i / 2];
            }
        }

        return result;
    }
};
