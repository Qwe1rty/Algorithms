#include <queue>
#include <vector>


/*
 * 215. Kth Largest Element in an Array
 * Medium
 *
 * O(n + k*log(k)) heapify + BFS solution
 * Runtime: 16 ms, faster than 45.40%
 * Memory Usage: 9.4 MB, less than 60.61%
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