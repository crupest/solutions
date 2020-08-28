#include <string>

using std::string;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0;

        int secret_digit_count[10] = {0};

        auto secret_iter = secret.cbegin();
        auto guess_iter = guess.cbegin();

        while (secret_iter != secret.cend())
        {
            auto secret_digit = *secret_iter;
            auto guess_digit = *guess_iter;

            secret_digit_count[secret_digit - '0']++;

            if (secret_digit == guess_digit)
                a++;

            ++secret_iter;
            ++guess_iter;
        }

        int b = 0;
        for (auto c : guess)
        {
            auto digit = c - '0';
            if (secret_digit_count[digit])
            {
                b++;
                secret_digit_count[digit]--;
            }
        }

        return std::to_string(a) + "A" + std::to_string(b - a) + "B";
    }
};
