#include <algorithm>
#include <map>
#include <set>
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


/*
 * 18. 4Sum
 * Medium
 *
 * pruning solution
 * speed: 12ms, faster than 99.89%
 * memory: 9.2MB, less than 100%
 *
 * https://leetcode.com/problems/4sum/
 */
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

    int n = nums.size();

    auto resultVector = std::vector<std::vector<int>>();
    if (n < 4) return std::move(resultVector);

    std::sort(nums.begin(), nums.end());

    for (int l = 0; l < n - 3; l++) {
        if (l > 0 && nums[l] == nums[l - 1]) continue;

        for (int r = l + 1; r < n - 2; r++) {
            if (r > l + 1 && nums[r] == nums[r - 1]) continue;

            int li = r + 1, ri = n - 1, prune = target - nums[l] - nums[r];
            while (li < ri) {

                if (nums[li] + nums[li + 1] > prune) break;
                if (nums[ri] + nums[ri - 1] < prune) break;

                if      (li > r + 1 && nums[li] == nums[li - 1]) { ++li; continue; }
                else if (ri < n - 1 && nums[ri] == nums[ri + 1]) { --ri; continue; }

                int sum = nums[l] + nums[li] + nums[ri] + nums[r];
                if      (sum < target) ++li;
                else if (sum > target) --ri;
                else {
                    resultVector.push_back({nums[l], nums[li], nums[ri], nums[r]});
                    ++li;
                    --ri;
                }
            }
        }
    }

    return std::move(resultVector);
}

/*
 * 2Sum + 2Sum = 4Sum strategy solution
 * speed: 348ms, faster than 6.58%
 * memory: 86.7MB, less than 5.21%
 *
 * https://leetcode.com/problems/4sum/
 */
std::vector<std::vector<int>> fourSum2(std::vector<int>& nums, int target) {

    auto resultVector = std::vector<std::vector<int>>();
    if (nums.size() < 4) return std::move(resultVector);

    std::sort(nums.begin(), nums.end());
    auto alphaTable = std::map<int, std::map<int, int>>();
    auto seenPairs  = std::map<int, std::set<int>>();

    for (int i = 0; i < nums.size() - 1; i++) {
        int ival = nums[i];
        if (seenPairs.count(ival)) continue;

        for (int j = i + 1; j < nums.size(); j++) {
            int jval = nums[j];
            if (seenPairs[ival].count(jval)) continue;

            seenPairs[ival].insert(jval);
            alphaTable[ival + jval][i] = j;
        }
    }

    seenPairs.clear();

    for (int bj = nums.size() - 1; bj > 0; bj--) {
        int bjval = nums[bj];
        if (seenPairs.count(bjval)) continue;

        for (int bi = bj - 1; bi >= 0; bi--) {
            int bival = nums[bi];
            if (seenPairs[bjval].count(bival)) continue;

            seenPairs[bjval].insert(bival);

            int beta  = bival + bjval,
                alpha = target - beta;

            const auto& alphaPairs = alphaTable[alpha];
            for (const auto& alphaPair : alphaPairs) {
                if (alphaPair.second < bi) {
                    resultVector.push_back({
                        nums[alphaPair.first],
                        nums[alphaPair.second],
                        bival,
                        bjval
                    });
                }
            }
        }
    }

    return std::move(resultVector);
}


/*
 * 42. Trapping Rain Water
 * Hard
 *
 * Two pointers solution
 * speed: 8ms, faster than 98.98%
 * memory: 9.1MB, less that 99.63%
 *
 * https://leetcode.com/problems/trapping-rain-water/
 */
int trap(const std::vector<int>& height) {

    if (height.empty()) return 0;

    int water = 0;
    int l = 0, r = height.size() - 1;
    int level = height[l] < height[r] ? height[l] : height[r];

    while (l < r) {
        if (height[l] <= height[r]) {
            if (level > height[l]) {
                water += level - height[l];
            } else if (level < height[l]) {
                level = height[l];
            }
            l++;
        } else if (height[l] > height[r]) {
            if (level > height[r]) {
                water += level - height[r];
            } else if (level < height[r]) {
                level = height[r];
            }
            r--;
        }
    }

    return water;
}