struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int visited[1001] {0};
    int result = 0;

    void DFS(TreeNode* r) {
      if (!visited[r->val]) {
        result += 1;
        visited[r->val] = 1;
      }

      if (r->left) DFS(r->left);
      if (r->right) DFS(r->right);
    }

    int numColor(TreeNode* root) {
      DFS(root);
      return result;
    }
};