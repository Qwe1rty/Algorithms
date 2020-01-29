#include <vector>


/*
 * 11. Container With Most Water
 * Medium
 *
 * speed: 20ms, faster than 98.41%
 * memory: 9.7MB, less than 99.72%
 *
 * https://leetcode.com/problems/container-with-most-water/
 */
int areaf(int i, int j, int ih, int jh) {
  int x = j - i;
  if (ih < jh) {
    return x * ih ;
  } else {
    return x * jh;
  }
}

int maxArea(std::vector<int>& height) {

  int i = 0;
  int j = height.size() - 1;
  int pi = -1;
  int pj = -1;

  int ih = height[i];
  int jh = height[j];

  int area = 0;
  int barea = areaf(i, j, ih, jh);

  while (true) {

    if (ih < jh) {
      while (ih >= height[i] && i < j) i += 1;
    } else {
      while (height[j] <= jh && i < j) j -= 1;
    }

    ih = height[i];
    jh = height[j];
    area = areaf(i, j, ih, jh);

    if (area > barea) barea = area;

    if (pi == i && pj == j) break;

    pi = i;
    pj = j;
  }

  return barea;
}