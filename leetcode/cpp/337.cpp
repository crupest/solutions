#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct SubTreeResult
{
    SubTreeResult(int use_root, int not_use_root) : use_root(use_root), not_use_root(not_use_root), max(use_root > not_use_root ? use_root : not_use_root) {}

    const int use_root;
    const int not_use_root;
    const int max;
};

class Solution
{
public:
    static SubTreeResult subtree_rob(TreeNode *root)
    {
        SubTreeResult left = root->left != NULL ? subtree_rob(root->left) : SubTreeResult{0, 0};
        SubTreeResult right = root->right != NULL ? subtree_rob(root->right) : SubTreeResult{0, 0};
        const auto use_root_value = root->val + left.not_use_root + right.not_use_root;
        const auto not_use_root_value = left.max + right.max;
        return SubTreeResult{use_root_value, not_use_root_value};
    }

    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return subtree_rob(root).max;
    }
};
