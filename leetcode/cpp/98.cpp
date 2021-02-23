#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <limits>

class Solution
{
public:
    bool dfs(TreeNode *node, long long min, long long max)
    {
        if (node == nullptr)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        return dfs(node->left, min, node->val) && dfs(node->right, node->val, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return dfs(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};
