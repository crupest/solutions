class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            if (__builtin_smul_overflow(result, 10, &result))
                return 0;
            if (__builtin_sadd_overflow(result, digit, &result))
                return 0;
        }
        return result;
    }
};
