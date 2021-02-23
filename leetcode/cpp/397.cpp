class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == 2147483647)
            return 32;

        int count = 0;

        while (n != 1)
        {
            if (n == 2)
            {
                count += 1;
                break;
            }
            if (n == 3)
            {
                count += 2;
                break;
            }
            if (n % 2 == 0)
            {
                count += 1;
                n /= 2;
                continue;
            }
            if ((n - 1) % 4 == 0)
            {
                count += 3;
                n = (n - 1) / 4;
                continue;
            }
            if ((n + 1) % 4 == 0)
            {
                count += 3;
                n = (n + 1) / 4;
                continue;
            }
            count += 2;
            n = (n - 1) / 2;
        }

        return count;
    }
};
