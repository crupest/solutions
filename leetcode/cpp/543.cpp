struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <algorithm>

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    int max = 0;
    depth(root, max);
    return max;
  }

  static int depth(TreeNode *root, int &max) {
    if (root == nullptr)
      return -1;

    auto left = depth(root->left, max) + 1;
    auto right = depth(root->right, max) + 1;

    auto current_max = left + right;
    if (current_max > max) {
      max = current_max;
    }

    return std::max(left, right);
  }
};
