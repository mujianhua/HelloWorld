#include "tree.h"

#include <queue>

using namespace std;

class Solution {
 public:
  // 遍历统一形式

  // 层序遍历
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      vector<int> vec;
      int size = que.size();  // que.size() 不断变化
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        vec.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      res.push_back(vec);
    }
    return res;
  }

  // 二叉树右视图
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        if (i == size - 1) res.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
    }
    return res;
  }
};

int main() {
  Solution ss;
  return 0;
}
