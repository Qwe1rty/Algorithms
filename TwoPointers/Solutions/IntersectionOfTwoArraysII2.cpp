#include <vector>
#include <map>


/*
 * 350. Intersection of Two Arrays II
 * Easy
 *
 * Hashmap O(m + n) solution
 * speed: 4 ms, faster than 99.21%
 * memory: 8.7 MB, less than 100.00%
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 */
std::vector<int> intersect2(const std::vector<int>& nums1, const std::vector<int>& nums2) {

  std::map<int, int> map{};
  for (const auto& num : nums2) {
    ++map[num];
  }

  std::vector<int> result;

  for (const auto& num : nums1) {
    if (map.count(num)) {
      if (map[num] > 0) {
        --map[num];
        result.emplace_back(num);
      }
      else {
        map.erase(num);
      }
    }
  }

  return std::move(result);
}