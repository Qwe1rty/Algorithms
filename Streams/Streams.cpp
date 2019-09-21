#include <deque>
#include <vector>
#include <unordered_map>


struct ListNode {

  int val;
  ListNode* next;

  explicit ListNode(int x) :
    val(x),
    next(nullptr)
  {}
};


/*
 * 239. Sliding Window Maximum
 * Hard
 *
 * speed: 56ms, faster than 83.42%
 * memory: 12.8MB, less than 98.36%
 *
 * https://leetcode.com/problems/sliding-window-maximum/
 */
std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {

  if (nums.size() < k) return std::vector<int>{};
  if (k == 1) return nums;

  std::deque<int> candidates{0};
  std::vector<int> result;
  result.reserve(nums.size() - k + 1);

  for (int i = 1; i < nums.size(); ++i) {

    if (candidates.front() <= i - k) candidates.pop_front();

    while (!candidates.empty() && nums[candidates.back()] <= nums[i]) {
      candidates.pop_back();
    }
    candidates.emplace_back(i);

    if (i >= k - 1) result.emplace_back(nums[candidates.front()]);
  }

  return result;
}


/*
 * 21. Merge Two Sorted Lists
 * Easy
 *
 * speed: 4ms, faster than 98.39%
 * memory: 8.8MB, less than 97.54%
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  while (l1 != nullptr || l2 != nullptr) {

    ListNode* append;

    if (l2 == nullptr) {
      append = l1;
      l1 = nullptr;
    }
    else if (l1 == nullptr) {
      append = l2;
      l2 = nullptr;
    }
    else if (l1->val < l2->val) {
      append = l1;
      l1 = l1->next;
    }
    else {
      append = l2;
      l2 = l2->next;
    }

    if (tail != nullptr) tail->next = append;
    tail = append;

    if (head == nullptr) head = tail;
  }

  return head;
}


/*
 * 19. Remove Nth Node From End of List
 * Medium
 *
 * Single pass two-pointer solution
 * speed: 4ms, faster than 85.71%
 * memory: 8.4MB, less than 100%
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {

  // assumes n > 0
  ListNode* fast = head;

  for (int i = 0; i <= n; ++i) {
    if (fast == nullptr) return head->next;
    else fast = fast->next;
  }

  ListNode* slow = head;

  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  slow->next = slow->next->next;
  return head;
}


/*
 * 128. Longest Consecutive Sequence
 * Hard
 *
 * O(n) range merging via hash map
 * speed: 12ms, faster than 69.90%
 * memory: 10.1MB, less than 67.31%
 *
 * https://leetcode.com/problems/longest-consecutive-sequence
 */

int longestConsecutive(const std::vector<int>& nums) {

  int max = 0;
  std::unordered_map<int, int> lookup;

  for (const auto num : nums) {
    if (lookup.count(num) == 0) {

      lookup[num] = 1;

      bool lower = lookup.count(num - 1);
      bool upper = lookup.count(num + 1);

      if (lower) lookup[num] += lookup[num - 1];
      if (upper) lookup[num] += lookup[num + 1];

      if (lower) lookup[num - lookup[num - 1]] = lookup[num];
      if (upper) lookup[num + lookup[num + 1]] = lookup[num];

      if (lookup[num] > max) max = lookup[num];
    }
  }

  return max;
}


/*
 * 53. Maximum Subarray
 * Easy
 *
 * O(n) solution
 * speed: 4 ms, faster than 98.61%
 * memory: 9.2 MB, less than 93.14%
 *
 * https://leetcode.com/problems/maximum-subarray/
 */
int maxSubArray(const std::vector<int>& nums) {

  int max = nums[0];
  int prev = 0;

  for (const auto& elem : nums) {
    if (elem > prev && prev < 0) {
      prev = elem;
    }
    else {
      prev += elem;
    }

    if (prev > max) max = prev;
  }

  return max;
}