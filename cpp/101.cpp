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
    static bool check(TreeNode *left, TreeNode *right)
    {
        if (left == NULL)
        {
            if (right == NULL)
                return true;
            else
                return false;
        }
        else
        {
            if (right == NULL)
                return false;
            else
            {
                if (left->val != right->val)
                    return false;
                return check(left->left, right->right) && check(left->right, right->left);
            }
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return check(root->left, root->right);
    }
};
