#include <vector>
#include <set>

using std::vector;

class Solution {
public:

    void DFS(int length, const std::vector<int>& nums, std::vector<int>& visited, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (length == 0) {
            result.push_back(current);
        }

        int used[21] {0};

        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = 1;

            int num = nums[i];

            if (!used[num + 10]) {
                current.push_back(nums[i]);
                DFS(length - 1, nums, visited, current, result);
                current.pop_back();
                used[num + 10] = 1;
            }

            visited[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<int> visited(nums.size());
        std::vector<int> current;
        std::vector<std::vector<int>> result;
        DFS(nums.size(),nums, visited, current, result);
        return result;
    }
};