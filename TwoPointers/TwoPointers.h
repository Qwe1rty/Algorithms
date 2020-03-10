#ifndef CLION_TWOPOINTERS_H
#define CLION_TWOPOINTERS_H

#include <vector>

/*
 * Easy
 */

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
std::vector<int> intersect2(std::vector<int>& nums1, std::vector<int>& nums2);

/*
 * Medium
 */

// 11. Container With Most Water
int maxArea(std::vector<int>& height);

// 18. 4Sum
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
std::vector<std::vector<int>> fourSum2(std::vector<int>& nums, int target);

/*
 * Hard
 */

// 42. Trapping Rain Water
int trap(const std::vector<int>& height);

// 128. Longest Consecutive Sequence
int longestConsecutive(const std::vector<int>& nums);


#endif //CLION_TWOPOINTERS_H