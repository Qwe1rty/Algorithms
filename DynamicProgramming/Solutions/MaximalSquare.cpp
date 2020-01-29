#include <algorithm
#include <vector>


/*
 * 221. Maximal Square
 * Medium
 *
 * speed: 20ms, faster than 98.02%
 * memory: 10.4MB, less than 100%
 *
 * https://leetcode.com/problems/maximal-square/
 */
int maximalSquare(std::vector<std::vector<char>>& matrix) {

  if (matrix.empty() || matrix[0].empty()) return 0;

  int largest = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (i != 0 && j != 0 && matrix[i][j] == '1') {
        matrix[i][j] = 1 + std::min({
                                      matrix[i][j - 1],
                                      matrix[i - 1][j],
                                      matrix[i - 1][j - 1]
                                    });
      }
      int diff = matrix[i][j] - '0';
      if (diff > largest) largest = diff;
    }
  }

  return largest * largest;
}