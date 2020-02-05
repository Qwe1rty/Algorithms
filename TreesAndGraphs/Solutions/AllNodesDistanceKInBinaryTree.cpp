#include <queue>
#include <map>
#include <unordered_set>
#include <vector>

#include "../Structures/TreeNode.h"


/*
 * 863. All Nodes Distance K in Binary Tree
 * Medium
 *
 * speed: 4 ms, faster than 95.00%
 * memory: 17.9 MB, less than 18.18%
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */

void buildParents(std::map<const TreeNode*, const TreeNode*>& parents,
                  const TreeNode* const node) {

  if (node->left != nullptr) {
    parents.insert({node->left, node});
    buildParents(parents, node->left);
  }
  if (node->right != nullptr){
    parents.insert({node->right, node});
    buildParents(parents, node->right);
  }
}

std::vector<int> distanceK(const TreeNode* const root,
                           const TreeNode* const target,
                           const int K) {

  if (root == nullptr || target == nullptr) return std::vector<int>{};

  std::map<const TreeNode*, const TreeNode*> parents{};
  buildParents(parents, root);

  int level = 0;
  std::unordered_set<const TreeNode*> visited{};
  std::queue<const TreeNode*> queue{};
  queue.push(target);

  while (level < K) {
    std::queue<const TreeNode*> next_queue{};

    while (!queue.empty()) {
      const TreeNode* node = queue.front();

      if (node->left && !visited.count(node->left)) {
        next_queue.push(node->left);
      }
      if (node->right && !visited.count(node->right)) {
        next_queue.push(node->right);
      }
      if (parents.count(node) && !visited.count(parents.at(node))) {
        next_queue.push(parents.at(node));
      }

      visited.insert(node);
      queue.pop();
    }

    queue = std::move(next_queue);
    ++level;
  }

  std::vector<int> result{};
  result.reserve(queue.size());

  while (!queue.empty()) {
    result.emplace_back(queue.front()->val);
    queue.pop();
  }

  return result;
}