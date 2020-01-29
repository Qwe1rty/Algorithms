#include <vector>


/*
 * 88. Merge Sorted Array
 * Easy
 *
 * speed: 0ms, faster than 100%
 * memory: 8.6MB, less than 100%
 *
 * https://leetcode.com/problems/merge-sorted-array/
 */
void merge(std::vector<int>& nums1,
           int m,
           const std::vector<int>& nums2,
           int n) {

  --m;
  --n;

  int i = n + m + 1;

  while (m >= 0 && n >= 0) {
    if (nums1[m] > nums2[n]) {
      nums1[i] = nums1[m];
      --m;
    }
    else{
      nums1[i] = nums2[n];
      --n;
    }
    --i;
  }

  while (n >= 0) {
    nums1[i] = nums2[n];
    --n;
    --i;
  }
}