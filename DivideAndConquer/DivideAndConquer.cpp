#include "../Streams/Streams.h"

#include <algorithm>
#include <queue>
#include <vector>


/*
 * 23. Merge k Sorted Lists
 * Hard
 *
 * O(n*log(k)) top-down divide and conquer solution
 * speed: 20ms, faster than 98.80%
 * memory: 11.1MB, less than 72.62%
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/
 */
ListNode* mergeKListsImpl(std::vector<ListNode*>& lists, int l, int r) {

  int m = (r + l) / 2;
  return mergeTwoLists(
    m - l > 1 ? mergeKListsImpl(lists, l, m) : lists[l],
    r - m > 1 ? mergeKListsImpl(lists, m, r) : lists[m]
  );
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {

  switch (lists.size()) {
    case 0: return nullptr;
    case 1: return lists[0];
    default: return mergeKListsImpl(lists, 0, lists.size());
  }
}


/*
 * 215. Kth Largest Element in an Array
 * Medium
 *
 * O(n) divide and conquer solution
 * speed: 8ms, faster than 97.54%
 * memory: 9.2 MB, less than 93.94%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest(std::vector<int>& nums, int k) {

  int l = 0;
  int r = nums.size();
  const int kr = r - k;

  while (r - l > 1) {

    std::swap(nums[l], nums[(l + r) / 2]);
    int li = l + 1;
    int ri = l + 1;

    // LL traversal partitioning logic, pivot located at (li - 1) afterwards
    while (ri < r) {
      if (nums[ri] < nums[l]) {
        std::swap(nums[li], nums[ri]);
        ++li;
      }
      ++ri;
    }
    std::swap(nums[l], nums[li - 1]);

    if (li - 1 < kr) {
      l = li;
    }
    else if (li - 1 > kr) {
      r = li - 1;
    }
    else break;
  }

  return nums[kr];
}

/*
 * O(n + k*log(k)) heapify + BFS solution
 * speed: 16 ms, faster than 45.40%
 * memory: 9.4 MB, less than 60.61%
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
int findKthLargest2(std::vector<int>& nums, int k) {

  if (nums.empty()) return 0;
  std::make_heap(nums.begin(), nums.end());

  std::priority_queue<std::pair<int, int>> sorter;
  sorter.emplace(std::pair<int, int>{nums[0], 0});

  for (int i = 0; i < k - 1; ++i) {
    auto top = sorter.top();
    sorter.pop();

    int ceil = 2 * top.second + 1;
    for (int child = ceil;
         child < nums.size() && child < ceil + 2;
         ++child) {
      sorter.emplace(std::pair<int, int>{nums[child], child});
    }
  }

  return sorter.top().first;
}


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


/*
 * 973. K Closest Points to Origin
 * Medium
 *
 * O(n) quick select solution
 * speed: 200 ms, faster than 97.28%
 * memory: 38.9 MB, less than 78.13%
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/
 */
/*
Test cases
[[1,3],[-2,2],[2,-2]]
2
[[9,-6],[-10,2],[4,0],[5,8],[-10,10],[-7,4],[-2,6]]
6
[[0,1],[1,0]]
2
[[1,3],[-2,2]]
1
 */
std::vector<std::vector<int>>
kClosest(std::vector<std::vector<int>>& points, int K) {

  struct Distance {
    int dist;
    const std::vector<int>* point;

    bool operator< (const Distance& src) {
      return dist < src.dist;
    }
  };

  std::vector<Distance> distances;
  distances.reserve(points.size());

  for (const auto& point : points) {
    distances.emplace_back(Distance{
      point[0] * point[0] + point[1] * point[1],
      &point
    });
  }

  int l = 0;
  int r = points.size();

  while (r - l > 1) {

    std::swap(distances[l], distances[(r + l) / 2]);

    int li = l + 1;
    int ri = l + 1;

    while (ri < r) {
      if (distances[ri] < distances[l]) {
        std::swap(distances[li], distances[ri]);
        ++li;
      }
      ++ri;
    }
    std::swap(distances[li - 1], distances[l]);

    if (li > K) {
      r = li - 1;
    }
    else if (li < K) {
      l = li;
    }
    else break;
  }

  std::vector<std::vector<int>> result;
  result.reserve(K);

  for (int i = 0; i < K; ++i) {
    result.emplace_back(*distances[i].point);
  }

  return result;
}


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


/*
 * O(n + m) walking solution
 * speed: 72 ms, faster than 54.23%
 * memory: 12.8MB, less than 93.33%
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