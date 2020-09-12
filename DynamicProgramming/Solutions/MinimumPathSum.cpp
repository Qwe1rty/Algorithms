#include <vector>


/*
 * 64. Minimum Path Sum
 * Medium
 *
 * Runtime: 12ms, faster than 98.07%
 * Memory Usage: 10.6MB, less than 99.37%
 *
 * https://leetcode.com/problems/minimum-path-sum/
 */
int minPathSum(std::vector<std::vector<int>>& grid) {

  if (grid.empty() || grid[0].empty()) return 0;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (!(i == 0 && j == 0)) {
        if      (i == 0) grid[i][j] += grid[i][j - 1];
        else if (j == 0) grid[i][j] += grid[i - 1][j];
        else grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
      }
    }
  }

  return grid[grid.size() - 1][grid[0].size() - 1];
}