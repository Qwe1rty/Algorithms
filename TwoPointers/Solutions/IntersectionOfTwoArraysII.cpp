#include <vector>
#include <algorithm>


/*
 * 350. Intersection of Two Arrays II
 * Easy
 *
 * Sorting arrays solution O(nlog(n) + mlog(m))
 * speed: 4 ms, faster than 99.21%
 * memory: 8 MB, less than 100.00%
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 */
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {

  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());

  std::vector<int> result;

  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i] < nums2[j]) {
      ++i;
    }
    else if (nums1[i] > nums2[j]) {
      ++j;
    }
    else {
      result.emplace_back(nums1[i]);
      ++i;
      ++j;
    }
  }

  return std::move(result);
}