#include <unordered_map>


/*
 * 242. Valid Anagram
 * Easy
 *
 * speed: 20ms, faster than 45.33%
 * memory: 9.2MB, less than 36.61%
 *
 * https://leetcode.com/problems/valid-anagram/
 */
bool isAnagram(const std::string& src, const std::string& dst)
{
  if (src.length() != dst.length()) return false;

  auto comp = std::unordered_map<char, std::pair<unsigned int, unsigned int>>();
  for (const char& c : src) comp[c].first++;
  for (const char& c : dst)
  {
    if (!comp.count(c)) return false;
    auto& pair = comp[c];
    if (pair.first == pair.second) return false;
    ++pair.second;
  }

  for (const auto& p : comp)
  {
    if (p.second.first != p.second.second) return false;
  }
  return true;
}
