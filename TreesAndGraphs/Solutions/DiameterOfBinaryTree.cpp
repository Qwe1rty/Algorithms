#include "../Structures/TreeNode.h"
#include <algorithm>


/*
 * 543. Diameter of Binary Tree
 * Easy
 *
 * Runtime: 16 ms, faster than 69.10%
 * Memory Usage: 20.7 MB, less than 89.44%
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/
 */

int diameter{0};

// Return longest chain, record max when both chains put together
int findDiameter(const TreeNode* const root) {

  if (root == nullptr) return 0;

  int leftLongestChain = findDiameter(root->left);
  int rightLongestChain = findDiameter(root->right);

  if (leftLongestChain + rightLongestChain > diameter) {
    diameter = leftLongestChain + rightLongestChain;
  }

  return std::max(leftLongestChain, rightLongestChain) + 1;
}

int diameterOfBinaryTree(const TreeNode* const root) {
  findDiameter(root);
  return diameter;
}

