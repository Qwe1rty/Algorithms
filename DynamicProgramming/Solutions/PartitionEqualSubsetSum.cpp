#include <map>
#include <vector>


/*
 * 416. Partition Equal Subset Sum
 * Medium
 *
 * Top-down (memoization) DP solution
 * speed: 8ms, faster than 92.42%
 * memory: 9.9MB, less than 39.38%
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/
 */
bool canPartitionImpl(
  std::map<int, bool>& dp,
  const std::vector<int>& nums,
  const int sum,
  const int index) {

  if (!dp.count(sum)) {
    if (index < 0) {
      return false;
    } else if (nums[index] == sum) {
      dp[sum] = true;
    } else if (nums[index] > sum) {
      dp[sum] = canPartitionImpl(dp, nums, sum, index - 1);
    } else {
      dp[sum] = canPartitionImpl(dp, nums, sum - nums[index], index - 1) ||
                canPartitionImpl(dp, nums, sum, index - 1);
    }
  }
  return dp[sum];
}

bool canPartition(std::vector<int>& nums) {

  int sum = 0;
  for (const int num : nums) sum += num;
  if (sum % 2 == 1) return false;

  auto dp = std::map<int, bool>();
  return canPartitionImpl(dp, nums, sum / 2, nums.size() - 1);
}