#ifndef CLION_SLIDINGWINDOW_H
#define CLION_SLIDINGWINDOW_H

#include <string>
#include <vector>

/*
 * Easy
 */

// 53. Maximum Subarray
int maxSubArray(const std::vector<int>& nums);

/*
 * Hard
 */

// 239. Sliding Window Maximum
std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k);

// 76. Minimum Window Substring
std::string minWindow(const std::string& s, const std::string& t);


#endif //CLION_SLIDINGWINDOW_H
