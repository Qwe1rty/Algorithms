#include <stack>
#include <vector>


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