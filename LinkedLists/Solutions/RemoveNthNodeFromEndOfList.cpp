#include "../ListNode.h"


/*
 * 19. Remove Nth Node From End of List
 * Medium
 *
 * Single pass two-pointer solution
 * speed: 4ms, faster than 85.71%
 * memory: 8.4MB, less than 100%
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {

  // assumes n > 0
  ListNode* fast = head;

  for (int i = 0; i <= n; ++i) {
    if (fast == nullptr) return head->next;
    else fast = fast->next;
  }

  ListNode* slow = head;

  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  slow->next = slow->next->next;
  return head;
}