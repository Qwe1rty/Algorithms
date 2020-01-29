#include <unordered_map>


/*
 * 3. Longest Substring Without Repeating Characters
 * Medium
 *
 * speed: 20ms, faster than 74.33%
 * memory: 10.8MB, less than 69.10%
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 */
int lengthOfLongestSubstring(const std::string& s) {

  if (s.empty()) return 0;

  std::unordered_map<char, int> lead;
  int largest = 1;

  int low = -1;
  for (int i = 0; i < s.length(); i++) {

    if (lead.count(s[i]) && lead[s[i]] > low) low = lead[s[i]];
    lead[s[i]] = i;

    int sublength = i - low;
    if (sublength > largest) largest = sublength;
  }

  return largest;
}
