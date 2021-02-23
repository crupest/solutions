#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <algorithm>

struct Result
{
    // root_camera >= root_monitored >= root_not_monitored
    int root_camera;
    int root_monitored;
    int root_not_monitored;
};

class Solution
{
public:
    Result dfs(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return Result{1, 1, 0};
        }

        if (root->left == nullptr || root->right == nullptr)
        {
            TreeNode *child_node = root->left == nullptr ? root->right : root->left;
            Result child = dfs(child_node);

            int root_camera = 1 + child.root_not_monitored;
            int root_monitored = std::min({child.root_camera,
                                           root_camera});
            int root_not_monitored = std::min(child.root_monitored, root_monitored);

            return Result{
                root_camera, root_monitored, root_not_monitored};
        }

        Result left = dfs(root->left);
        Result right = dfs(root->right);

        int root_camera = 1 + left.root_not_monitored + right.root_not_monitored;
        int root_monitored = std::min({left.root_camera + right.root_monitored,
                                       left.root_monitored + right.root_camera,
                                       root_camera});
        int root_not_monitored = std::min({left.root_monitored + right.root_monitored, root_monitored});

        return Result{
            root_camera, root_monitored, root_not_monitored};
    }

    int minCameraCover(TreeNode *root)
    {
        auto result = dfs(root);
        return result.root_monitored;
    }
};