#include <vector>


/*
 * 307. Range Sum Query - Mutable
 * Medium
 *
 * precalculated ranges, O(log(n)) queries
 * speed: 44 ms, faster than 49.80%
 * memory: 33.7 MB, less than 8.33%
 *
 * https://leetcode.com/problems/range-sum-query-mutable/
 */
class NumArray {

  class SumNode;

  SumNode* const root;
  const std::vector<int>& nums;

  class SumNode {
    const std::pair<int, int> range;
    const int mid;
    SumNode* const left;
    SumNode* const right;

    int sum;

  public:
    SumNode(std::pair<int, int> range, const std::vector<int>& nums) :
      range{std::move(range)},
      mid{(floor() + ceil()) / 2},
      left{
        is_leaf() ?
          nullptr :
          new SumNode({floor(), mid}, nums)
      },
      right{
        is_leaf() ?
          nullptr :
          new SumNode({mid, ceil()}, nums)
      },
      sum{
        is_leaf() ?
          nums[floor()] :
          left->sum + right->sum
      }
    {}

    int query(int lo, int hi) const {

      if (span() == hi - lo) {
        return sum;
      }
      else if (hi <= mid) {
        return left->query(lo, hi);
      }
      else if (lo >= mid) {
        return right->query(lo, hi);
      }

      return left->query(lo, mid) + right->query(mid, hi);
    }

    void update(int i, int val) {

      // assume i == left is true for now
      if (is_leaf()) {
        sum = val;
        return;
      }

      (i < mid ? left : right)->update(i, val);
      sum = left->sum + right->sum;
    }

    int floor() const {
      return range.first;
    }

    int ceil() const {
      return range.second;
    }

    int span() const {
      return ceil() - floor();
    }

    bool is_leaf() const {
      return span() == 1;
    };
  };

public:
  explicit NumArray(const std::vector<int>& nums) :
    nums{nums},
    root{
      nums.empty() ?
        nullptr :
        new SumNode({0, nums.size()}, nums)
    }
  {}

  void update(int i, int val) {
    if (root) root->update(i, val);
  }

  int sumRange(int i, int j) const {
    return root ? root->query(i, j + 1) : 0;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */