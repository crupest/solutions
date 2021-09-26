#include <vector>

using std::vector;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;

        for (int i = 1; i < nums.size(); i++) {
          for (int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];
            if (diff > result) {
              result = diff;
            }
          }
        }

        return result == 0 ? -1 : result;
    }
};