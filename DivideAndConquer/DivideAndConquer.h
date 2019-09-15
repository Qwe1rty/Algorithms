#ifndef CLION_DIVIDEANDCONQUER_H
#define CLION_DIVIDEANDCONQUER_H

#include <vector>

class ListNode;

/*
 * Medium
 */
int findKthLargest(std::vector<int>& nums, int k);

/*
 * Hard
 */

// 23. Merge k Sorted Lists
ListNode* mergeKLists(std::vector<ListNode*>& lists);
ListNode* mergeKLists2(std::vector<ListNode*>& lists);

#endif //CLION_DIVIDEANDCONQUER_H
