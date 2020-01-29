#include <unordered_map>
#include <vector>


/*
 * 128. Longest Consecutive Sequence
 * Hard
 *
 * O(n) range merging via hash map
 * speed: 12ms, faster than 69.90%
 * memory: 10.1MB, less than 67.31%
 *
 * https://leetcode.com/problems/longest-consecutive-sequence
 */

int longestConsecutive(const std::vector<int>& nums) {

  int max = 0;
  std::unordered_map<int, int> lookup;

  for (const auto num : nums) {
    if (lookup.count(num) == 0) {

      lookup[num] = 1;

      bool lower = lookup.count(num - 1);
      bool upper = lookup.count(num + 1);

      if (lower) lookup[num] += lookup[num - 1];
      if (upper) lookup[num] += lookup[num + 1];

      if (lower) lookup[num - lookup[num - 1]] = lookup[num];
      if (upper) lookup[num + lookup[num + 1]] = lookup[num];

      if (lookup[num] > max) max = lookup[num];
    }
  }

  return max;
}