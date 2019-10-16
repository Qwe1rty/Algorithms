#ifndef CLION_DYNAMICPROGRAMMING_H
#define CLION_DYNAMICPROGRAMMING_H

#include <string>
#include <vector>

/*
 * Easy
 */

// 121. Best Time to Buy and Sell Stock
int maxProfit(const std::vector<int>& prices);

/*
 * Medium
 */

// 50. Pow(x, n)
double myPow(double x, int n);

// 416. Partition Equal Subset Sum
bool canPartition(std::vector<int>& nums);
bool canPartition2(std::vector<int>& nums);

// 62. Unique Paths
int uniquePaths(int m, int n);

// 300. Longest Increasing Subsequence
int lengthOfLIS(const std::vector<int>& nums);

// 64. Minimum Path Sum
int minPathSum(std::vector<std::vector<int>>& grid);

// 221. Maximal Square
int maximalSquare(std::vector<std::vector<char>>& matrix);

/*
 * Hard
 */

// 741. Cherry Pickup
int cherryPickup(const std::vector<std::vector<int>>& grid);
int cherryPickupI(std::vector<std::vector<int>>& grid);

// 174. Dungeon Game (incorrect solution)
int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);

// 32. Longest Valid Parenthesis
int longestValidParentheses(const std::string& s);


#endif //CLION_DYNAMICPROGRAMMING_H
