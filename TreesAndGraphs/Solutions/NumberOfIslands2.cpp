#include <vector>


class UnionFind {

  int num_groups_;
  std::vector<int> group_sizes_;
  std::vector<int> elems_;

public:

  explicit UnionFind(int num_elems) :
    num_groups_(num_elems),
    group_sizes_(num_elems, 1),
    elems_(num_elems, 1)
  {
    for (int i = 0; i < num_elems; ++i) elems_[i] = i;
  }

  int find(int elem) {

    if (elems_[elem] == elem) {
      return elem;
    }

    return elems_[elem] = find(elems_[elem]);
  }

  void join(int e1, int e2) {

    int r1 = find(e1);
    int r2 = find(e2);

    if (r1 == r2) return;

    if (group_sizes_[r1] < group_sizes_[r2]) {
      elems_[e1] = elems_[r1] = r2;
      group_sizes_[r2] += group_sizes_[r1];
    }
    else {
      elems_[e2] = elems_[r2] = r1;
      group_sizes_[r1] += group_sizes_[r2];
    }

    --num_groups_;
  }

  int group_size(int elem) {
    return group_sizes_[find(elem)];
  }

  int num_groups() {
    return num_groups_;
  }
};

int elemOf(const std::vector<std::vector<char>>& grid, int row, int col) {
  return grid[row].size() * row + col;
}

int numIslands2(const std::vector<std::vector<char>>& grid) {

  if (grid.empty() || grid[0].empty()) return 0;

  UnionFind union_find(grid.size() * grid[0].size());
  int water_tiles{0};

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == '1') {
        if (i >= 1 && grid[i - 1][j] == '1') {
          union_find.join(elemOf(grid, i - 1, j), elemOf(grid, i, j));
        }
        if (j >= 1 && grid[i][j - 1] == '1') {
          union_find.join(elemOf(grid, i, j - 1), elemOf(grid, i, j));
        }
      }
      else ++water_tiles;
    }
  }

  return union_find.num_groups() - water_tiles;
}