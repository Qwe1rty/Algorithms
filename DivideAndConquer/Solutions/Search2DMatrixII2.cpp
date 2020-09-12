#include <vector>


/*
 * 240. Search a 2D Matrix II
 * Medium
 *
 * O(n + m) walking solution
 * Runtime: 72 ms, faster than 54.23%
 * Memory Usage: 12.8MB, less than 93.33%
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 */
bool searchMatrixII2(const std::vector<std::vector<int>>& matrix, int target) {

  if (matrix.empty()) return false;

  int x = matrix[0].size() - 1;
  int y = 0;

  while (y < matrix.size() && x >= 0) {
    if (matrix[y][x] < target) {
      ++y;
    }
    else if (matrix[y][x] > target) {
      --x;
    }
    else return true;
  }

  return false;
}