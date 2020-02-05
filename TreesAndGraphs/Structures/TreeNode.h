#ifndef CLION_TREENODE_H
#define CLION_TREENODE_H

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#endif //CLION_TREENODE_H
