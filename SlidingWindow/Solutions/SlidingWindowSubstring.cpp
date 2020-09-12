#include <string>
#include <map>

/*
 * 76. Minimum Window Substring
 * Hard
 *
 * Runtime: 52 ms, faster than 51.46%
 * Memory Usage: 7.8 MB, less than 67.97%
 *
 * https://leetcode.com/problems/minimum-window-substring/
 */
std::string minWindow(const std::string& s, const std::string& t) {

  bool valid{false};
  int targets_reached{0}, l{0}, r{0}, best_l{0}, best_r(s.size());
  std::map<char, int> targets{}, window_targets{};

  for (const char& c : t) ++targets[c];

  for (r = 0; r < s.size(); ++r) if (targets.count(s[r])) {

    ++window_targets[s[r]];
    if (window_targets[s[r]] == targets[s[r]]) ++targets_reached;

    while (targets_reached == targets.size()) {
      if (r - l < best_r - best_l) {
        best_r = r;
        best_l = l;
      }

      if (targets.count(s[l])) {
        --window_targets[s[l]];
        if (window_targets[s[l]] < targets[s[l]]) --targets_reached;
      }

      valid = true;
      ++l;
    }

  }

  return valid ? s.substr(best_l, best_r - best_l + 1) : "";
}
