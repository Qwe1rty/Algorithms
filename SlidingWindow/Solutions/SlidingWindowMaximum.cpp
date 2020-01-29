#include <deque>
#include <vector>


/*
 * 239. Sliding Window Maximum
 * Hard
 *
 * speed: 56ms, faster than 83.42%
 * memory: 12.8MB, less than 98.36%
 *
 * https://leetcode.com/problems/sliding-window-maximum/
 */
std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {

  if (nums.size() < k) return std::vector<int>{};
  if (k == 1) return nums;

  std::deque<int> candidates{0};
  std::vector<int> result;
  result.reserve(nums.size() - k + 1);

  for (int i = 1; i < nums.size(); ++i) {

    if (candidates.front() <= i - k) candidates.pop_front();

    while (!candidates.empty() && nums[candidates.back()] <= nums[i]) {
      candidates.pop_back();
    }
    candidates.emplace_back(i);

    if (i >= k - 1) result.emplace_back(nums[candidates.front()]);
  }

  return result;
}