#include <queue>
#include "../Structures/Node.h"


/*
 * 116. Populating Next Right Pointers in Each Node
 * Medium
 *
 * Runtime: 32 ms, faster than 47.81%
 * Memory Usage: 17.7 MB, less than 6.95%
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 */
Node* connect(Node* root) {

  if (!root) return root;

  Node* prev;
  std::queue<Node*> currentLevel, nextLevel;
  nextLevel.push(root);

  while (!nextLevel.empty()) {

    currentLevel = move(nextLevel);
    nextLevel = std::queue<Node*>();

    prev = nullptr;

    while (!currentLevel.empty()) {
      Node* curr = currentLevel.front();
      currentLevel.pop();

      curr->next = prev;
      prev = curr;

      if (curr->right) {
        nextLevel.push(curr->right);
        nextLevel.push(curr->left);
      }
    }
  }

  return root;
}
