#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    static bool traverse(TreeNode *root, int val)
    {
        if (root == NULL)
            return true;
        if (root->val != val)
            return false;
        return traverse(root->left, root->val) && traverse(root->right, root->val);
    }

    bool isUnivalTree(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return traverse(root, root->val);
    }
};