#ifndef CLION_TWOPOINTERS_H
#define CLION_TWOPOINTERS_H

#include <vector>

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


#endif //CLION_TWOPOINTERS_H