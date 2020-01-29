#include <vector>


/*
 * 240. Search a 2D Matrix II
 * Medium
 *
 * binary search windowing solution
 * O(min(n, m)) worst case
 * O(log(n*m)) average case but really high constant
 * speed: 112 ms, faster than 26.71%
 * memory: 12.8 MB, less than 93.33%
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 */
bool searchMatrixII(const std::vector<std::vector<int>>& matrix, int target) {

  if (matrix.empty() || matrix[0].empty()) return false;

  int t = 0;
  int b = matrix.size();

  int l = 0;
  int r = matrix[0].size();

  while (true) {

    if (t < b && l < matrix[0].size()) {

      // bsearch on left wall to get upper bound
      int ti = t, bi = b;
      while (ti < bi) {
        int m = (ti + bi) / 2;
        if (matrix[m][l] < target) ti = m + 1;
        else if (matrix[m][l] > target) bi = m;
        else return true;
      }
      b = ti;

      // bsearch on right wall to get lower bound
      ti = t, bi = b;
      while (ti < bi) {
        int m = (ti + bi) / 2;
        if (matrix[m][r - 1] < target) ti = m + 1;
        else if (matrix[m][r - 1] > target) bi = m;
        else return true;
      }
      t = ti;
    }
    else return false;

    ++l;
    --r;

    if (l < r && t < matrix.size()) {

      // bsearch on top wall to get upper bound
      int li = l, ri = r;
      while (li < ri) {
        int m = (li + ri) / 2;
        if (matrix[t][m] < target) li = m + 1;
        else if (matrix[t][m] > target) ri = m;
        else return true;
      }
      r = li;

      // bsearch on bottom wall to get lower bound
      li = l, ri = r;
      while (li < ri) {
        int m = (li + ri) / 2;
        if (matrix[b - 1][m] < target) li = m + 1;
        else if (matrix[b - 1][m] > target) ri = m;
        else return true;
      }
      l = li;
    }
    else return false;

    ++t;
    --b;
  }
}