#include <string>


/*
 * 331. Verify Preorder Serialization of a Binary Tree
 * Medium
 *
 * O(n) traversal, O(1) auxiliary memory
 * Runtime: 0 ms, faster than 100.00%
 * Memory Usage: 8.9 MB, less than 100.00%
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
 */
bool isValidSerialization(const std::string& preorder) {

  int bal = 0;

  for (int i = 0; i < preorder.size(); ++i) {
    if (preorder[i] == ',') {
      bal += '#' == preorder[i - 1] ? -1 : 1;
      if (bal < 0) return false;
    }
  }

  return bal == 0 && '#' == preorder.back();
}