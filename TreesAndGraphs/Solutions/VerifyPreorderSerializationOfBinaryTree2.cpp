#include <stack>
#include <string>


/*
 * 331. Verify Preorder Serialization of a Binary Tree
 * Medium
 *
 * O(n) traversal, O(n) memory stack-based solution
 * Runtime: 4 ms, faster than 91.25%
 * Memory Usage: 9 MB, less than 75.00%
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
 */
bool isValidSerialization2(const std::string& preorder) {

  if (preorder == "#") return true;
  std::stack<bool> children{};

  for (int i = 0; i <= preorder.size(); ++i) {
    if (preorder[i] == ',' || preorder[i] == '\0') {

      const char& elem = preorder[i - 1];
      if (elem == '#' && children.empty()) return false;

      if (!children.empty()) {
        if (children.top()) children.pop();
        else children.top() = true;
      }

      if (elem != '#') {
        children.push(false);
      }
      else if (children.empty() && preorder[i] != '\0') {
        return false;
      }
    }
  }

  return children.empty();
}
