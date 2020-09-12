#include <vector>


/*
 * 62. Unique Paths
 * Medium
 *
 * Runtime: 4ms, faster than 100%
 * Memory Usage: 8.7MB, less than 25.41
 *
 * https://leetcode.com/problems/unique-paths/
 */
int uniquePaths(int m, int n) {

  auto dp = std::vector<std::vector<int>>(
    m,
      std::vector<int>(n, 0)
  );

  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j != 0) dp[i][j] += dp[i][j - 1];
      if (i != 0) dp[i][j] += dp[i - 1][j];
    }
  }

  return dp[m - 1][n - 1];
}