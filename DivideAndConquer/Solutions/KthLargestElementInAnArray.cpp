#include <vector>


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