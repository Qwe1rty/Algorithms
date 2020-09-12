#include <vector>


/*
 * 416. Partition Equal Subset Sum
 * Medium
 *
 * Bottom-up (tabulation) DP solution
 * Runtime: 168ms, faster than 37.96%
 * Memory Usage: 8.5MB, less than 100%
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/
 */
bool canPartition2(std::vector<int>& nums) {

  int sum = 0;
  for (const auto& num : nums) sum += num;
  if (sum % 2 == 1) return false;
  sum /= 2;

  auto dp = std::vector<bool>(sum + 1, false);
  dp[0] = true;

  for (const int& num : nums) {
    for (int i = sum; i >= num; i--) {
      if (num <= i) {
        dp[i] = dp[i] || dp[i - num];
      }
    }
  }

  return dp[sum];
}