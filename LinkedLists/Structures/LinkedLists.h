#ifndef CLION_LINKEDLISTS_H
#define CLION_LINKEDLISTS_H

#include <vector>

class ListNode;

/*
 * Easy
 */

// 21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

/*
 * Medium
 */

// 19. Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n);

// 621. Task Scheduler (incorrect solution)
int leastInterval(const std::vector<char>& tasks, int n);


#endif //CLION_LINKEDLISTS_H
