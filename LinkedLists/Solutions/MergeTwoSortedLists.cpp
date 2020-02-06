#include "../Structures/ListNode.h"


/*
 * 21. Merge Two Sorted Lists
 * Easy
 *
 * speed: 4ms, faster than 98.39%
 * memory: 8.8MB, less than 97.54%
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  while (l1 != nullptr || l2 != nullptr) {

    ListNode* append;

    if (l2 == nullptr) {
      append = l1;
      l1 = nullptr;
    }
    else if (l1 == nullptr) {
      append = l2;
      l2 = nullptr;
    }
    else if (l1->val < l2->val) {
      append = l1;
      l1 = l1->next;
    }
    else {
      append = l2;
      l2 = l2->next;
    }

    if (tail != nullptr) tail->next = append;
    tail = append;

    if (head == nullptr) head = tail;
  }

  return head;
}