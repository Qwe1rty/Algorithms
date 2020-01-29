#include <vector>


/*
 * Easy
 * 121. Best Time to Buy and Sell Stock
 *
 * speed: 8 ms, faster than 65.82%
 * memory: 9.7 MB, less than 40.37%
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
int maxProfit(const std::vector<int>& prices) {

  if (prices.empty()) return 0;

  int max = prices.back();
  int transaction = 0;

  for (int i = prices.size() - 2; i >= 0; --i) {
    if (max - prices[i] > transaction) {
      transaction = max - prices[i];
    }
    if (prices[i] > max) {
      max = prices[i];
    }
  }

  return transaction;
}