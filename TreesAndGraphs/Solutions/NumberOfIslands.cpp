#include <vector>


/*
 * 200. Number of Islands
 * Medium
 *
 * O(w * h) DFS traversal
 * Runtime: 20 ms, faster than 27.27%
 * Memory Usage: 10.6 MB, less than 100.00%
 *
 * https://leetcode.com/problems/number-of-islands/submissions/
 */
void search(std::vector<std::vector<char>>& grid, int x, int y) {
  if (x >= grid.size() ||
      x < 0 ||
      y >= grid[0].size() ||
      y < 0)
    return;

  if (grid[x][y] == '1') {
    grid[x][y] = '0';
    search(grid, x + 1, y); // E
    search(grid, x, y + 1); // S
    search(grid, x - 1, y); // W
    search(grid, x, y - 1); // N
  }
}

int numIslands(std::vector<std::vector<char>>& grid) {

  int count = 0;

  for (int x = 0; x < grid.size(); ++x) {
    for (int y = 0; y < grid[0].size(); ++y) {
      if (grid[x][y] == '1') {
        ++count;
        search(grid, x, y);
      }
    }
  }

  return count;
}
