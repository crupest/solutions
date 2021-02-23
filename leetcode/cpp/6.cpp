#include <string>
#include <iostream>

using std::string;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        const auto length = s.size();
        const int count_per_group = numRows * 2 - 2;
        string result;
        result.reserve(length);
        for (int row = 0; row < numRows; row++)
        {
            if (row == 0)
            {
                for (int p = 0; p < length; p += count_per_group)
                    result += s[p];
            }
            else if (row == numRows - 1)
            {
                for (int p = row; p < length; p += count_per_group)
                    result += s[p];
            }
            else
            {
                bool former = true;
                const auto former_gap = count_per_group - row * 2;
                const auto latter_gap = count_per_group - former_gap;
                for (int p = row; p < length; p += (former ? former_gap : latter_gap), former = !former)
                    result += s[p];
            }
        }
        return result;
    }
};

int main()
{
    Solution s;

    auto result1 = s.convert("PAYPALISHIRING", 3);
    auto result2 = s.convert("PAYPALISHIRING", 4);
    std::cout
        << s.convert("A", 1) << '\n'
        << result1 << '\n'
        << "PAHNAPLSIIGYIR\n"
        << result2 << '\n'
        << "PINALSIGYAHRPI\n";
    return 0;
}