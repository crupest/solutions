#include <string>

using std::string;

class Solution
{
public:
    void longestWithCenter(const string &s, int length, int index, int *longest_start, int *longest_length_ptr)
    {
        int &longest_length = *longest_length_ptr;

        int palindrome_length_odd = index * 2 + 1 <= longest_length || (length - index - 1) * 2 + 1 <= longest_length ? 0 : 1;
        int palindrome_length_even = (index + 1) * 2 <= longest_length || (length - index - 1) * 2 <= longest_length ? 0 : 1;

        while (palindrome_length_odd || palindrome_length_even)
        {
            if (palindrome_length_odd)
            {
                int start = index - palindrome_length_odd;
                int end = index + palindrome_length_odd;
                if (start < 0)
                {
                    palindrome_length_odd = 0;
                }
                else if (end >= length)
                {
                    palindrome_length_odd = 0;
                }
                else
                {
                    if (s[start] == s[end])
                    {
                        int current_length = end - start + 1;
                        if (current_length > longest_length)
                        {
                            *longest_start = start;
                            longest_length = current_length;
                        }
                        palindrome_length_odd++;
                    }
                    else
                    {
                        palindrome_length_odd = 0;
                    }
                }
            }

            if (palindrome_length_even)
            {
                int start = index - palindrome_length_even + 1;
                int end = index + palindrome_length_even;
                if (start < 0)
                {
                    palindrome_length_even = 0;
                }
                else if (end >= length)
                {
                    palindrome_length_even = 0;
                }
                else
                {
                    if (s[start] == s[end])
                    {
                        int current_length = end - start + 1;
                        if (current_length > longest_length)
                        {
                            *longest_start = start;
                            longest_length = current_length;
                        }
                        palindrome_length_even++;
                    }
                    else
                    {
                        palindrome_length_even = 0;
                    }
                }
            }
        }
    }

    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int longest_start = 0;
        int longest_length = 1;
        int length = s.size();

        for (int i = 0; i < length; i++)
        {
            longestWithCenter(s, length, i, &longest_start, &longest_length);
        }

        return s.substr(longest_start, longest_length);
    }
};

int main()
{
    Solution s{};
    s.longestPalindrome("bb");
    return 0;
}
