#include <algorithm>
#include <vector>


/*
 * 741. Cherry Pickup
 * Hard
 *
 * Diagonal slicing DP strategy
 * speed: 40ms, faster than 84.56%
 * memory: 18.9MB, less than 44.74%
 *
 * https://leetcode.com/problems/cherry-pickup/
 */
int cherryPickup(const std::vector<std::vector<int>>& grid) {

  if (grid.empty() || grid[0].empty()) return 0;
  auto dp = std::vector<std::vector<int>>(
    1,
    std::vector<int>(1, grid[0][0])
  );

  int tmax = 2 * grid.size() - 1;

  for (int t = 1; t < tmax; t++) {

    bool retreating = t >= grid.size();
    int diag = retreating ? tmax - t : t + 1;

    auto curr = std::vector<std::vector<int>>(
      diag,
      std::vector<int>(diag, 0)
    );

    for (int r1 = 0; r1 < curr.size(); r1++) {
      for (int r2 = 0; r2 < curr.size(); r2++) {

        int r1a = r1, r2a = r2;

        if (retreating) {
          int adjustment = t - grid.size() + 1;
          r1a += adjustment;
          r2a += adjustment;
        }

        if (grid[r1a][t - r1a] == -1 || grid[r2a][t - r2a] == -1) {
          curr[r1][r2] = -1;
          continue;
        }

        int optimal = retreating ?
          std::max({
                     dp[r1][r2],
                     dp[r1][r2 + 1],
                     dp[r1 + 1][r2],
                     dp[r1 + 1][r2 + 1]
                   }) :
          std::max({
                     r1a != t && r2a != t ? dp[r1][r2] : -1,
                     r1a != t && r2a != 0 ? dp[r1][r2 - 1] : -1,
                     r1a != 0 && r2a != t ? dp[r1 - 1][r2] : -1,
                     r1a != 0 && r2a != 0 ? dp[r1 - 1][r2 - 1] : -1
                   });

        if (optimal != -1) {
          curr[r1][r2] = r1 == r2 ?
            grid[r1a][t - r1a] :
            grid[r1a][t - r1a] + grid[r2a][t - r2a];
        }

        curr[r1][r2] = curr[r1][r2] + optimal;
      }
    }

    dp = std::move(curr);
  }

  return std::max(dp[0][0], 0);
}


/*
 * 741. Cherry Pickup
 * Hard
 *
 * One-way greedy solution
 * Incorrect solution
 *
 * https://leetcode.com/problems/cherry-pickup/
 */
int cherryPickupI(std::vector<std::vector<int>>& grid) {

  if (grid.empty() || grid[0].empty()) return 0;

  auto dp = std::vector<std::vector<int>>(
    grid.size(),
      std::vector<int>(grid[0].size(), 0)
  );

  dp[0][0] = grid[0][0];
  for (int i = 0; i < dp.size(); i++) {
    for (int j = 0; j < dp[0].size(); j++) {
      if (grid[i][j] == -1 || (i == 0 && j == 0)) continue;
      else if (i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
      else if (j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
      else {
        int m = std::max(dp[i][j - 1], dp[i - 1][j]);
        if (m != 0) {
          dp[i][j] = grid[i][j] + m;
        }
      }
    }
  }

  if (dp[dp.size() - 1][dp[0].size() - 1] == 0) return 0;

  {
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    while ((i > 0 || j > 0) && dp[i][j] > 0) {
      if (i == 0 && j != 0) {
        if (dp[i][j - 1] < dp[i][j]) grid[i][j] = 0;
        j--;
      } else if (j == 0 && i != 0) {
        if (dp[i - 1][j] < dp[i][j]) grid[i][j] = 0;
        i--;
      } else if (dp[i][j - 1] > dp[i - 1][j]) { // path is left
        if (dp[i][j - 1] < dp[i][j]) grid[i][j] = 0;
        j--;
      } else {
        if (dp[i - 1][j] < dp[i][j]) grid[i][j] = 0;
        i--;
      }
    }
    grid[0][0] = 0;
  }

  for (int i = dp.size() - 1; i >= 0; i--) {
    for (int j = dp[0].size() - 1; j >= 0; j--) {
      if (grid[i][j] == -1 || (i == dp.size() - 1 && j == dp[0].size() - 1)) continue;
      else if (i == dp.size() - 1)    dp[i][j] = grid[i][j] + dp[i][j + 1];
      else if (j == dp[0].size() - 1) dp[i][j] = grid[i][j] + dp[i + 1][j];
      else dp[i][j] = grid[i][j] + std::max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  return dp[0][0];
}
