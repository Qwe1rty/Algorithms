#include "../Streams/Streams.h"

#include <algorithm>
#include <queue>
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


/*
 * 215. Kth Largest Element in an Array
 * Medium
 *
 * O(n) divide and conquer solution
 * speed: 8ms, faster than 97.54%
 * memory: 9.2 MB, less than 93.94%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest(std::vector<int>& nums, int k) {

  int l = 0;
  int r = nums.size();
  const int kr = r - k;

  while (r - l > 1) {

    std::swap(nums[l], nums[(l + r) / 2]);
    int li = l + 1;
    int ri = l + 1;

    // LL traversal partitioning logic, pivot located at (li - 1) afterwards
    while (ri < r) {
      if (nums[ri] < nums[l]) {
        std::swap(nums[li], nums[ri]);
        ++li;
      }
      ++ri;
    }
    std::swap(nums[l], nums[li - 1]);

    if (li - 1 < kr) {
      l = li;
    }
    else if (li - 1 > kr) {
      r = li - 1;
    }
    else break;
  }

  return nums[kr];
}

/*
 * O(n + k*log(k)) heapify + BFS solution
 * speed: 16 ms, faster than 45.40%
 * memory: 9.4 MB, less than 60.61%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest2(std::vector<int>& nums, int k) {

  if (nums.empty()) return 0;
  std::make_heap(nums.begin(), nums.end());

  std::priority_queue<std::pair<int, int>> sorter;
  sorter.emplace(std::pair<int, int>{nums[0], 0});

  for (int i = 0; i < k - 1; ++i) {
    auto top = sorter.top();
    sorter.pop();

    int ceil = 2 * top.second + 1;
    for (int child = ceil;
         child < nums.size() && child < ceil + 2;
         ++child) {
      sorter.emplace(std::pair<int, int>{nums[child], child});
    }
  }

  return sorter.top().first;
}