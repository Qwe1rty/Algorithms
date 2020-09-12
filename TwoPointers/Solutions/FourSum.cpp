#include <algorithm>
#include <vector>


/*
 * 18. 4Sum
 * Medium
 *
 * pruning solution
 * Runtime: 12ms, faster than 99.89%
 * Memory Usage: 9.2MB, less than 100%
 *
 * https://leetcode.com/problems/4sum/
 */
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

  int n = nums.size();

  auto resultVector = std::vector<std::vector<int>>();
  if (n < 4) return std::move(resultVector);

  std::sort(nums.begin(), nums.end());

  for (int l = 0; l < n - 3; l++) {
    if (l > 0 && nums[l] == nums[l - 1]) continue;

    for (int r = l + 1; r < n - 2; r++) {
      if (r > l + 1 && nums[r] == nums[r - 1]) continue;

      int li = r + 1, ri = n - 1, prune = target - nums[l] - nums[r];
      while (li < ri) {

        if (nums[li] + nums[li + 1] > prune) break;
        if (nums[ri] + nums[ri - 1] < prune) break;

        if      (li > r + 1 && nums[li] == nums[li - 1]) { ++li; continue; }
        else if (ri < n - 1 && nums[ri] == nums[ri + 1]) { --ri; continue; }

        int sum = nums[l] + nums[li] + nums[ri] + nums[r];
        if      (sum < target) ++li;
        else if (sum > target) --ri;
        else {
          resultVector.push_back({nums[l], nums[li], nums[ri], nums[r]});
          ++li;
          --ri;
        }
      }
    }
  }

  return std::move(resultVector);
}