#ifndef CLION_DIVIDEANDCONQUER_H
#define CLION_DIVIDEANDCONQUER_H

#include <vector>

class ListNode;

/*
 * Easy
 */

// 88. Merge Sorted Array
void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n);

/*
 * Medium
 */

// 215. Kth Largest Element in an Array
int findKthLargest(std::vector<int>& nums, int k);

// 973. K Closest Points to Origin
std::vector<std::vector<int>>
kClosest(std::vector<std::vector<int>>& points, int K);

// 74. Search a 2D Matrix
bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target);

// 240. Search a 2D Matrix II
bool searchMatrixII(const std::vector<std::vector<int>>& matrix, int target);
bool searchMatrixII2(const std::vector<std::vector<int>>& matrix, int target);

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
