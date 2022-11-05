#include "tree.h"

#include <limits.h>

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

  // 二叉树层平均值
  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> que;
    vector<double> res;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      double sum = 0;
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        sum += node->val;
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      res.push_back(sum / size);
    }
    return res;
  }

  /*
  // 429. N 叉树的层序遍历
  vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> que;
    vector<vector<int>> res;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      vector<int> vec;
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        Node* node = que.front();
        que.pop();
        vec.push_back(node->val);
        for (int j = 0; j < node->children.size(); ++j) {
          if (node->children[j]) que.push(node->children[j]);
        }
        // ??????????
        // for (Node* _node : node->children) {
        //   if (_node) que.push(node);
        // }
      }
      res.push_back(vec);
    }
    return res;
  }
  */

  // 515. 在每个树行中找最大值
  vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> que;
    vector<int> res;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      int max_val = INT_MIN;
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        max_val = max(max_val, node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      res.push_back(max_val);
    }
    return res;
  }

  // todo:
  Node* connect(Node* root) {
    queue<Node*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      Node* pre_node = nullptr;
      Node* node = nullptr;
      for (int i = 0; i < size; ++i) {
        if (i == 0) {
          pre_node = que.front();
          que.pop();
          node = pre_node;
        } else {
          node = que.front();
          que.pop();
          pre_node->next = node;
          pre_node = pre_node->next;
        }
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      pre_node->next = NULL;
    }
    return root;
  }

  int maxDepth(TreeNode* root) {
    int depth = 0;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      ++depth;
    }
    return depth;
  }

  // 111. 二叉树的最小深度
  // 只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点
  int minDepth(TreeNode* root) {
    int depth = 0;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
        if (!node->left && !node->right) return ++depth;  // 加本层depth
      }
      ++depth;
    }
    return depth;
  }
};

int main() {
  Solution ss;
  return 0;
}
