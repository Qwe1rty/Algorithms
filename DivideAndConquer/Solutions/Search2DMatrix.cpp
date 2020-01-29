#include <vector>


/*
 * 74. Search a 2D Matrix
 * Medium
 *
 * speed: 8 ms, faster than 93.59%
 * memory: 9.6 MB, less than 100.00%
 *
 * https://leetcode.com/problems/search-a-2d-matrix/
 */
bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {

  if (matrix.empty() || matrix[0].empty()) return false;

  int l = 0;
  int r = matrix.size();

  while (r - l > 1) {
    int m = (r + l) / 2;
    if (matrix[m][0] > target) {
      r = m;
    }
    else if (matrix[m][0] < target) {
      l = m;
    }
    else return true;
  }

  const std::vector<int>& row = matrix[l];

  l = 0;
  r = row.size();

  while (r - l > 1) {
    int m = (r + l) / 2;
    if (row[m] > target) {
      r = m;
    }
    else if (row[m] < target) {
      l = m;
    }
    else return true;
  }

  return row[l] == target;
}