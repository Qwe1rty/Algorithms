#include <queue>
#include <vector>
#include "../Structures/TreeNode.h"


/*
 * 637. Average of Levels in Binary Tree
 * Easy
 *
 * Runtime: 36 ms, faster than 19.12%
 * Memory Usage: 24.7 MB, less than 5.01%
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree
 */
std::vector<double> averageOfLevels(const TreeNode* const root) {

  double sum;
  std::queue<const TreeNode*> currentLevel, nextLevel;
  std::vector<double> answer{};

  nextLevel.push(root);

  while (!nextLevel.empty()) {
    sum = 0;

    currentLevel = move(nextLevel);
    nextLevel = std::queue<const TreeNode*>{};
    int currentLevelNodes = currentLevel.size();

    while (!currentLevel.empty()) {
      const auto node = currentLevel.front();

      sum += node->val;
      if (node->left != nullptr) nextLevel.push(node->left);
      if (node->right != nullptr) nextLevel.push(node->right);

      currentLevel.pop();
    }

    answer.emplace_back(sum / currentLevelNodes);
  }

  return move(answer);
}
