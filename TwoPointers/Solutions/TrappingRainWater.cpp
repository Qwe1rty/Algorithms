#include <vector>


/*
 * 42. Trapping Rain Water
 * Hard
 *
 * Two pointers solution
 * Runtime: 8ms, faster than 98.98%
 * Memory Usage: 9.1MB, less that 99.63%
 *
 * https://leetcode.com/problems/trapping-rain-water/
 */
int trap(const std::vector<int>& height) {

  if (height.empty()) return 0;

  int water = 0;
  int l = 0, r = height.size() - 1;
  int level = height[l] < height[r] ? height[l] : height[r];

  while (l < r) {
    if (height[l] <= height[r]) {
      if (level > height[l]) {
        water += level - height[l];
      } else if (level < height[l]) {
        level = height[l];
      }
      l++;
    } else if (height[l] > height[r]) {
      if (level > height[r]) {
        water += level - height[r];
      } else if (level < height[r]) {
        level = height[r];
      }
      r--;
    }
  }

  return water;
}