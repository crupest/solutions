#include <string>

using std::string;

const char *roman_digits = "IVXLCDM";

class Solution
{
public:
    string intToRoman(int num)
    {
        string result;

        int current_digit_index = 0;

        while (num != 0)
        {
            const int digit = num % 10;
            if (digit == 9)
            {
                result += roman_digits[current_digit_index + 2];
                result += roman_digits[current_digit_index];
            }
            else if (digit <= 8 && digit >= 5)
            {
                for (int i = 0; i < digit - 5; i++)
                {
                    result += roman_digits[current_digit_index];
                }
                result += roman_digits[current_digit_index + 1];
            }
            else if (digit == 4)
            {
                result += roman_digits[current_digit_index + 1];
                result += roman_digits[current_digit_index];
            }
            else
            {
                for (int i = 0; i < digit; i++)
                {
                    result += roman_digits[current_digit_index];
                }
            }

            num /= 10;
            current_digit_index += 2;
        }

        return string(result.crbegin(), result.crend());
    }
};