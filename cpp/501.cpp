#include <cstddef>
#include <vector>

using std::vector;

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
    void dfs(TreeNode *node, int &last, int &count, int &max_count, vector<int> &result)
    {
        if (node == nullptr)
            return;

        dfs(node->left, last, count, max_count, result);

        auto current = node->val;
        if (current == last)
        {
            count += 1;
        }
        else
        {
            count = 1;
        }

        if (count == max_count)
        {
            result.push_back(current);
        }
        else if (count > max_count)
        {
            max_count = count;
            result.clear();
            result.push_back(current);
        }

        last = current;
        dfs(node->right, last, count, max_count, result);
    }

    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        int last = 0, count = 0, max_count = 0;
        vector<int> result;
        dfs(root, last, count, max_count, result);
        return result;
    }
};
