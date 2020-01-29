#include <vector>


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