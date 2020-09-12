#include <queue>
#include <vector>
#include "../Structures/TreeNode.h"


/*
 * 102. Binary Tree Level Order Traversal
 * Medium
 *
 * Runtime: 12 ms, faster than 17.44%
 * Memory Usage: 12.4 MB, less than 97.94%
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal
 */

struct LevelNode {
  const int level;
  const TreeNode* node;

  LevelNode(int level, const TreeNode* node) :
    level{level},
    node{node}
  {}
};

std::vector<std::vector<int>> levelOrder(const TreeNode* root) {

  std::vector<std::vector<int>> solution;
  if (!root) return solution;

  std::queue<LevelNode> bfs;
  bfs.push(LevelNode(0, root));

  while (!bfs.empty()) {
    const auto levelNode = bfs.front();

    if (levelNode.level >= solution.size()) solution.emplace_back();
    solution[levelNode.level].emplace_back(levelNode.node->val);

    if (levelNode.node->left) bfs.push(LevelNode(levelNode.level + 1, levelNode.node->left));
    if (levelNode.node->right) bfs.push(LevelNode(levelNode.level + 1, levelNode.node->right));

    bfs.pop();
  }

  return solution;
}