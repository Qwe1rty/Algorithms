#include <vector>


/*
 * 174. Dungeon Game
 * Hard
 *
 * incorrect solution
 *
 * https://leetcode.com/problems/dungeon-game/
 */
int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {

  if (dungeon.empty() || dungeon[0].empty()) return 1;

  auto current = std::vector<std::vector<int>>(
    dungeon.size(),
      std::vector<int>(dungeon[0].size(), 0)
  );

  current[0][0] = 1 + std::max(0, dungeon[0][0]);
  dungeon[0][0] = 1 + std::max(0, -dungeon[0][0]);

  for (int i = 0; i < dungeon.size(); i++) {
    for (int j = 0; j < dungeon[0].size(); j++) {

      if (i != 0 && j != 0) {
        int tDiff = current[i - 1][j] + dungeon[i][j];
        int tIncr = dungeon[i - 1][j] + std::max(1 - tDiff, 0);
        int lDiff = current[i][j - 1] + dungeon[i][j];
        int lIncr = dungeon[i][j - 1] + std::max(1 - lDiff, 0);

        if (tIncr == lIncr) {
          dungeon[i][j] = tIncr;
          current[i][j] = std::max({tDiff, lDiff, 1});
        } else if (tIncr < lIncr) {
          dungeon[i][j] = tIncr;
          current[i][j] = std::max(tDiff, 1);
        } else {
          dungeon[i][j] = lIncr;
          current[i][j] = std::max(lDiff, 1);
        }

      } else if (i == 0 && j != 0) {
        int lDiff = current[i][j - 1] + dungeon[i][j];
        dungeon[i][j] = dungeon[i][j - 1] + std::max(1 - lDiff, 0);
        current[i][j] = std::max(lDiff, 1);

      } else if (j == 0 && i != 0) {
        int tDiff = current[i - 1][j] + dungeon[i][j];
        dungeon[i][j] = dungeon[i - 1][j] + std::max(1 - tDiff, 0);
        current[i][j] = std::max(tDiff, 1);
      }

    }
  }

//        for (int i = 0; i < dungeon.size(); i++) {
//            cout << "[ ";
//            for (int j = 0; j < dungeon[0].size(); j++) {
//                cout << dungeon[i][j] << ' ';
//            }
//            cout << ']' << endl;
//        }
//        for (int i = 0; i < dungeon.size(); i++) {
//            cout << "[ ";
//            for (int j = 0; j < dungeon[0].size(); j++) {
//                cout << current[i][j] << ' ';
//            }
//            cout << ']' << endl;
//        }

  return dungeon[dungeon.size() - 1][dungeon[0].size() - 1];
}