#include <string>
#include <vector>


/*
 * 32. Longest Valid Parentheses
 * Hard
 *
 * O(n) bottom-up solution
 * speed: 4ms, faster than 96.01%
 * memory: 9.4MB, less than 85.71%
 *
 * https://leetcode.com/problems/longest-valid-parentheses
 */
int longestValidParentheses(const std::string& s) {

  if (s.size() <= 1) return 0;
  std::vector<int> dp(s.size(), 0);

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ')') {
      bool matched = false;
      for (int j = i - 1; j >= 0;) { // loop bounded by constant
        if (s[j] == '(') {
          if (!matched) {
            dp[i] += 2;
            --j;
            matched = true;
          }
          else break;
        }
        else if (dp[j] > 0) {
          dp[i] += dp[j];
          j -= dp[j];
        }
        else break;
      }
      if (!matched) dp[i] = 0;
    }
  }

  int max = 0;
  for (const auto& val : dp) {
    if (val > max) max = val;
  }

  return max;
}