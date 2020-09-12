#ifndef CLION_TREES_H
#define CLION_TREES_H

#include <string>
#include <vector>
#include "Structures/TreeNode.h"

/*
 * Easy
 */

// 543. Diameter of Binary Tree
int diameterOfBinaryTree(const TreeNode* root);

// 637. Average of Levels in Binary Tree
std::vector<double> averageOfLevels(const TreeNode* const root)

/*
 * Medium
 */

struct TreeNode;

// 94. Binary Tree Inorder Traversal
std::vector<int> inorderTraversal(TreeNode* root);

// 200. Number of Islands
int numIslands(std::vector<std::vector<char>>& grid);
int numIslands2(const std::vector<std::vector<char>>& grid);

// 331. Verify Preorder Serialization of a Binary Tree
bool isValidSerialization(const std::string& preorder);
bool isValidSerialization2(const std::string& preorder);


#endif //CLION_TREES_H