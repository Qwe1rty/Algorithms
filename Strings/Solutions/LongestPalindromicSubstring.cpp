#include <unordered_map>


/*
 * 5. Longest Palindromic Substring
 * Medium
 *
 * speed: 20ms, faster than 76.32%
 * memory: 8.6MB, less than 100%
 *
 * https://leetcode.com/problems/longest-palindromic-substring/
 */
std::string longestPalindrome(const std::string& s) {

  int l = 0;
  int r = 0;

  int max = 1;
  int lm = 0;

  while (r < s.size()) {

    int length = l == r;
    int d =      l == r;

    while (l - d >= 0 && r + d < s.size()) {
      if (s[l - d] == s[r + d]) {
        length += 2;
        ++d;
      }
      else break;
    }

    if (length > max) {
      max = length;
      lm = l - d + 1;
    }

    if (l == r) ++r;
    else ++l;
  }

  return s.substr(lm, max);
}