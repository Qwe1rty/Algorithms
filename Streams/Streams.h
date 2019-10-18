#ifndef CLION_STREAMS_H
#define CLION_STREAMS_H

#include <vector>

class ListNode;

/*
 * Easy
 */

// 21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

// 53. Maximum Subarray
int maxSubArray(const std::vector<int>& nums);

/*
 * Medium
 */

// 19. Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n);

// 621. Task Scheduler (incorrect solution)
int leastInterval(const std::vector<char>& tasks, int n);

/*
 * Hard
 */

// 239. Sliding Window Maximum
std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k);

// 128. Longest Consecutive Sequence
int longestConsecutive(const std::vector<int>& nums);


#endif //CLION_STREAMS_H
