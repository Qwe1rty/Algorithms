#include <climits>
#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>



/*
 * Medium
 * 621. Task Scheduler
 *
 * incorrect solution
 *
 * https://leetcode.com/problems/task-scheduler/
 */
/*
Test cases:
["A","A","A","B","B","B"]
2
["A","A","A","A","A","A","B","C","D","E","F","G"]
2
*/
int leastInterval(const std::vector<char>& tasks, int n) {

  std::unordered_map<char, int> counter{};
  for (const auto& task : tasks) {
    ++counter[task];
  }

  struct Node {
    char letter;
    int remaining;
    int timestamp;

    Node& operator= (const Node& src) {
      letter = src.letter;
      remaining = src.remaining;
      timestamp = src.timestamp;
      return *this;
    }
    bool operator< (const Node& src) const {
      // reversed so heap acts as min heap instead of max heap
      return
        (timestamp == src.timestamp && remaining < src.remaining) ||
        timestamp > src.timestamp;
    }
  };

  std::priority_queue<Node> queue{};
  for (const auto& count : counter) {
    queue.emplace(Node{
      count.first,
      count.second,
      INT_MIN
    });
  }

  int i = 0;
  for (; !queue.empty(); ++i) {
    Node task(queue.top());
    if (i > n + task.timestamp) {
      queue.pop();
      task.timestamp = i;
      --task.remaining;

      if (task.remaining > 0) {
        queue.emplace(task);
      }
    }
  }

  return i;
}