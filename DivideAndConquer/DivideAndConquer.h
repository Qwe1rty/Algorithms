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

// 218. The Skyline Problem
std::vector<std::vector<int>>
getSkyline(const std::vector<std::vector<int>>& buildings);


#endif //CLION_DIVIDEANDCONQUER_H
