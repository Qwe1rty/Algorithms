#include <vector>


/*
 * 218. The Skyline Problem
 * Hard
 *
 * O(n*log(n)) divide and conquer solution
 * speed: 76 ms, faster than 11.73%
 * memory: 49 MB, less than 7.69%
 *
 * https://leetcode.com/problems/the-skyline-problem/
 */
/*
Test cases:
[[0,2,3],[2,5,3]]
[[2,4,7],[2,4,5],[2,4,6]]
[[1,2,1],[1,2,2],[1,2,3]]
[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
[[0,5,7],[5,10,7],[5,10,12],[10,15,7],[15,20,7],[15,20,12],[20,25,7]]
 */
std::vector<std::vector<int>>
mergeSkyline(
  std::vector<std::vector<int>>&& lpartition,
  std::vector<std::vector<int>>&& rpartition) {

  int li = 0;
  int ri = 0;

  int loc = 0;
  int lheight = 0;
  int rheight = 0;
  int cheight = 0;

  std::vector<std::vector<int>> merged;
  merged.reserve(lpartition.size() + rpartition.size());

  while (li < lpartition.size() || ri < rpartition.size()) {

    if (li >= lpartition.size()) {
      merged.emplace_back(std::move(rpartition[ri]));
      ++ri;
      continue;
    }
    else if (ri >= rpartition.size()) {
      merged.emplace_back(std::move(lpartition[li]));
      ++li;
      continue;
    }

    if (lpartition[li][0] == rpartition[ri][0]) {
      loc = lpartition[li][0];
      lheight = lpartition[li][1];
      rheight = rpartition[ri][1];
      ++li;
      ++ri;
    }
    else if (lpartition[li][0] < rpartition[ri][0]) {
      loc = lpartition[li][0];
      lheight = lpartition[li][1];
      ++li;
    }
    else {
      loc = rpartition[ri][0];
      rheight = rpartition[ri][1];
      ++ri;
    }

    int max = std::max(lheight, rheight);
    if (max != cheight) {
      merged.emplace_back(std::vector<int>{loc, max});
      cheight = max;
    }
  }

  return merged;
}

std::vector<std::vector<int>>
partitionSkyline(
  const std::vector<std::vector<int>>& buildings,
  int l,
  int r) {

  if (r - l > 1) {
    int m = (l + r) / 2;
    return mergeSkyline(
      partitionSkyline(buildings, l, m),
      partitionSkyline(buildings, m, r)
    );
  }

  return std::vector<std::vector<int>>{
    {buildings[l][0], buildings[l][2]},
    {buildings[l][1], 0}
  };
}

std::vector<std::vector<int>>
getSkyline(const std::vector<std::vector<int>>& buildings) {

  if (buildings.empty()) return std::vector<std::vector<int>>{};
  return partitionSkyline(buildings, 0, buildings.size());
}