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
 * O(n + k*log(k)) heapify + BFS solution
 * speed: 16 ms, faster than 45.40%
 * memory: 9.4 MB, less than 60.61%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest(std::vector<int>& nums, int k) {

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

/*
 * O(n*log(n)) "for fun" solution
 * speed: 8 ms, faster than 97.59%
 * memory: 9.2 MB, less than 86.36%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest2(std::vector<int>& nums, int k) {

  sort(nums.begin(), nums.end(), std::greater<>());
  return nums[k - 1];
}