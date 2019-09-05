#include <iostream>
#include <map>
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

    auto comp = std::map<char, std::pair<unsigned int, unsigned int>>();
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