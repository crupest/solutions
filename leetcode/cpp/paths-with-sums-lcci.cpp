#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>

class Solution
{
public:
    std::vector<int> current;

    int dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;

        current.push_back(root->val);

        int s = 0;
        int count = 0;

        for (auto iter = current.crbegin(); iter != current.crend(); ++iter)
        {
            s += *iter;
            if (s == sum)
                count++;
        }

        count += dfs(root->left, sum) + dfs(root->right, sum);

        current.pop_back();

        return count;
    }

    int pathSum(TreeNode *root, int sum)
    {
        return dfs(root, sum);
    }
};
