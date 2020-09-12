#include "../Structures/Node.h"


/*
 * 116. Populating Next Right Pointers in Each Node
 * Medium
 *
 * Runtime: 28 ms, faster than 76.50%
 * Memory Usage: 16.7 MB, less than 81.68%
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 */

Node* connect2(Node* const root) {

  Node* nextLevel = root;

  while (nextLevel && nextLevel->left) {
    Node* current = nextLevel;
    nextLevel = current->left;

    while (current) {
      current->left->next = current->right;
      if (current->next) current->right->next = current->next->left;
      current = current->next;
    }
  }

  return root;
}