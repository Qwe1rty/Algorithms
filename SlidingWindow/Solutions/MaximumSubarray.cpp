#include <deque>
#include <vector>


/*
 * 53. Maximum Subarray
 * Easy
 *
 * O(n) solution
 * Runtime: 4 ms, faster than 98.61%
 * Memory Usage: 9.2 MB, less than 93.14%
 *
 * https://leetcode.com/problems/maximum-subarray/
 */
int maxSubArray(const std::vector<int>& nums) {

  int max = nums[0];
  int prev = 0;

  for (const auto& elem : nums) {
    if (elem > prev && prev < 0) {
      prev = elem;
    }
    else {
      prev += elem;
    }

    if (prev > max) max = prev;
  }

  return max;
}