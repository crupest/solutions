struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>

class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        std::queue<TreeNode *> odd_level;
        std::queue<TreeNode *> even_level;

        even_level.push(root);

        while (true)
        {
            if (!odd_level.empty())
            {
                auto node = odd_level.front();
                odd_level.pop();
                if (node->left)
                    even_level.push(node->left);
                if (node->right)
                    even_level.push(node->right);
                int last = node->val;
                if (last % 2 != 0)
                    return false;

                while (!odd_level.empty())
                {
                    node = odd_level.front();
                    odd_level.pop();
                    if (node->left)
                        even_level.push(node->left);
                    if (node->right)
                        even_level.push(node->right);
                    int val = node->val;
                    if (val % 2 != 0)
                        return false;
                    if (val >= last)
                        return false;
                    last = val;
                }

                continue;
            }

            if (!even_level.empty())
            {
                auto node = even_level.front();
                even_level.pop();
                if (node->left)
                    odd_level.push(node->left);
                if (node->right)
                    odd_level.push(node->right);
                int last = node->val;
                if (last % 2 == 0)
                    return false;

                while (!even_level.empty())
                {
                    node = even_level.front();
                    even_level.pop();
                    if (node->left)
                        odd_level.push(node->left);
                    if (node->right)
                        odd_level.push(node->right);
                    int val = node->val;
                    if (val % 2 == 0)
                        return false;
                    if (val <= last)
                        return false;
                    last = val;
                }

                continue;
            }

            break;
        }

        return true;
    }
};