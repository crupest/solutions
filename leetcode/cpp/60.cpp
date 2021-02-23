#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        k--;
        
        string result;
        result.reserve(n);

        std::vector<char> nums;
        nums.reserve(n);

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i + '0');
        }

        n--;
        int fac = 1;
        for (int i = 2; i <= n; i++)
        {
            fac *= i;
        }

        while (n > 0)
        {
            const int index = k / fac;
            k = k % fac;
            result += nums[index];
            nums.erase(nums.cbegin() + index);
            fac /= n--;
        }

        result += nums.front();

        return result;
    }
};