#ifndef CLION_DIVIDEANDCONQUER_H
#define CLION_DIVIDEANDCONQUER_H

#include <vector>

class ListNode;

/*
 * Medium
 */

// 215. Kth Largest Element in an Array
int findKthLargest(std::vector<int>& nums, int k);

// 973. K Closest Points to Origin
std::vector<std::vector<int>>
kClosest(std::vector<std::vector<int>>& points, int K);

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
