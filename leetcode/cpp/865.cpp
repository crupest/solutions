struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <unordered_set>

class Solution
{
public:
    int max_depth = -1;
    std::unordered_set<TreeNode *> deepest_nodes;

    void record_depth(TreeNode *root, int depth)
    {
        if (depth > max_depth)
        {
            max_depth = depth;
            deepest_nodes.clear();
        }

        if (depth == max_depth)
            deepest_nodes.insert(root);

        if (root->left != nullptr)
            record_depth(root->left, depth + 1);
        if (root->right != nullptr)
            record_depth(root->right, depth + 1);
    }

    TreeNode *find_common_ancestor(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (deepest_nodes.find(root) != deepest_nodes.cend())
            return root;

        auto left = find_common_ancestor(root->left);
        auto right = find_common_ancestor(root->right);

        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;
        return nullptr;
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        record_depth(root, 0);
        return find_common_ancestor(root);
    }
};
