#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool carry = true;
        const auto end = digits.rend();
        for (auto iter = digits.rbegin(); carry && iter != end; ++iter)
        {
            auto &digit = *iter;
            digit += 1;
            if (digit == 10)
            {
                digit = 0;
                carry = true;
            }
            else
            {
                carry = false;
            }
        }

        if (carry)
        {
            digits.insert(digits.cbegin(), 1);
        }

        return digits;
    }
};
