#ifndef CLION_TREES_H
#define CLION_TREES_H

#include <string>
#include <vector>
#include "Structures/TreeNode.h"
#include "Structures/Node.h"

/*
 * Easy
 */

// 543. Diameter of Binary Tree
int diameterOfBinaryTree(const TreeNode* root);

// 637. Average of Levels in Binary Tree
std::vector<double> averageOfLevels(const TreeNode* const root);

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

// 102. Binary Tree Level Order Traversal
std::vector<std::vector<int>> levelOrder(const TreeNode* root);

// 116. Populating Next Right Pointers in Each Node
Node* connect(Node* root);
Node* connect2(Node* root);


#endif //CLION_TREES_H