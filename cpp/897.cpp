/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::vector<TreeNode*> result;

    void InOrderTraverse(TreeNode* root) {
        if (root->left != nullptr)
            InOrderTraverse(root->left);
        result.push_back(root);
        if (root->right != nullptr)
            InOrderTraverse(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        InOrderTraverse(root);

        const auto end = result.end();
        auto iter1 = result.begin();
        auto iter2 = result.begin() + 1;
        for (; iter2 != end; ++iter1, ++iter2) {
            const auto node = *iter1;
            node->left = NULL;
            node->right = *iter2;
        }
        (*iter1)->left = (*iter1)->right = NULL;

        return result.front();
    }
};
