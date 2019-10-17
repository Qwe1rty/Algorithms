#include "Stack.h"

#include <stack>
#include <vector>


/*
 * Medium
 * 456. 132 Pattern
 *
 * O(n) stack + min array solution
 * speed: 24 ms, faster than 83.92%
 * memory: 10.9 MB, less than 25.00%
 *
 * https://leetcode.com/problems/132-pattern/
 */
bool find132pattern(const std::vector<int>& nums) {

  if (nums.size() <= 2) return false;

  std::vector<int> min;
  min.reserve(nums.size());
  min.push_back(nums[0]);

  int m = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < m) m = nums[i];
    min.push_back(m);
  }

  std::stack<int> s;

  for (int i = nums.size() - 1; i >= 0; --i) {
    while (!s.empty() && s.top() < nums[i]) {
      if (s.top() > min[i]) return true;
      else s.pop();
    }
    s.push(nums[i]);
  }

  return false;
}


/*
 * Medium
 * 739. Daily Temperatures
 *
 * speed: 192 ms, faster than 79.72%
 * memory: 14.8 MB, less than 96.00%
 *
 * https://leetcode.com/problems/daily-temperatures/
 */
std::vector<int> dailyTemperatures(const std::vector<int>& T) {

  if (T.empty()) return std::vector<int>{};

  std::vector<int> result(T.size(), 0);
  std::stack<int> s;

  for (int i = T.size() - 1; i >= 0; --i) {
    while (!s.empty() && T[i] >= T[s.top()]) {
      s.pop();
    }
    result[i] = s.empty() ? 0 : s.top() - i;
    s.push(i);
  }

  return result;
}