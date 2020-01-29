#include <vector>


/*
 * 300. Longest Increasing Subsequence
 * Medium
 *
 * Bottom-up O(n^2) DP solution
 * speed: 40ms, faster than 53.38%
 * memory: 8.8MB, less than 49.74%
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/
 */
int lengthOfLIS(const std::vector<int>& nums) {

  if (nums.size() <= 1) return nums.size();

  int highest = 1;
  auto dp = std::vector<int>(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
    }
    if (dp[i] > highest) highest = dp[i];
  }

  return highest;
}