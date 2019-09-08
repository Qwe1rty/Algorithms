#include "../Streams/Streams.h"

#include <vector>


/*
 * 23. Merge k Sorted Lists
 * Hard
 *
 * O(n*log(k)) top-down divide and conquer solution
 * speed: 20ms, faster than 98.80%
 * memory: 11.1MB, less than 72.62%
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/
 */
ListNode* mergeKListsImpl(std::vector<ListNode*>& lists, int l, int r) {

  int m = (r + l) / 2;
  return mergeTwoLists(
    m - l > 1 ? mergeKListsImpl(lists, l, m) : lists[l],
    r - m > 1 ? mergeKListsImpl(lists, m, r) : lists[m]
  );
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {

  switch (lists.size()) {
    case 0: return nullptr;
    case 1: return lists[0];
    default: return mergeKListsImpl(lists, 0, lists.size());
  }
}