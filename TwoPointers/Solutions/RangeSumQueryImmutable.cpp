#include <vector>


/*
 * 303. Range Sum Query - Immutable
 * Easy
 *
 * O(n) startup, O(1) prefix sum array solution
 * speed: 60 ms, faster than 21.13%
 * memory: 17.2 MB, less than 93.10%
 *
 * https://leetcode.com/problems/range-sum-query-immutable/submissions/
 */
class NumArray {
  std::vector<int> prefixSum;

public:
  explicit NumArray(const std::vector<int>& nums) {
    prefixSum.reserve(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      prefixSum.emplace_back(nums[i]);
      if (i > 0) prefixSum[i] += prefixSum[i - 1];
    }
  }

  int sumRange(int i, int j) {
    int tail = prefixSum[j];
    int head = [this, &i] {
      if (i == 0) return 0;
      else return prefixSum[i - 1];
    }();
    return tail - head;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */