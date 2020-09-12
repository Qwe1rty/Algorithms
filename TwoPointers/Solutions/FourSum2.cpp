#include <algorithm>
#include <map>
#include <set>
#include <vector>


/*
 * 18. 4Sum
 * Medium
 *
 * 2Sum + 2Sum = 4Sum strategy solution
 * Runtime: 348ms, faster than 6.58%
 * Memory Usage: 86.7MB, less than 5.21%
 *
 * https://leetcode.com/problems/4sum/
 */
std::vector<std::vector<int>> fourSum2(std::vector<int>& nums, int target) {

  auto resultVector = std::vector<std::vector<int>>();
  if (nums.size() < 4) return std::move(resultVector);

  std::sort(nums.begin(), nums.end());
  auto alphaTable = std::map<int, std::map<int, int>>();
  auto seenPairs  = std::map<int, std::set<int>>();

  for (int i = 0; i < nums.size() - 1; i++) {
    int ival = nums[i];
    if (seenPairs.count(ival)) continue;

    for (int j = i + 1; j < nums.size(); j++) {
      int jval = nums[j];
      if (seenPairs[ival].count(jval)) continue;

      seenPairs[ival].insert(jval);
      alphaTable[ival + jval][i] = j;
    }
  }

  seenPairs.clear();

  for (int bj = nums.size() - 1; bj > 0; bj--) {
    int bjval = nums[bj];
    if (seenPairs.count(bjval)) continue;

    for (int bi = bj - 1; bi >= 0; bi--) {
      int bival = nums[bi];
      if (seenPairs[bjval].count(bival)) continue;

      seenPairs[bjval].insert(bival);

      int beta  = bival + bjval,
        alpha = target - beta;

      const auto& alphaPairs = alphaTable[alpha];
      for (const auto& alphaPair : alphaPairs) {
        if (alphaPair.second < bi) {
          resultVector.push_back({
                                   nums[alphaPair.first],
                                   nums[alphaPair.second],
                                   bival,
                                   bjval
                                 });
        }
      }
    }
  }

  return std::move(resultVector);
}