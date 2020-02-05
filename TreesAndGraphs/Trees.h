#ifndef CLION_TREES_H
#define CLION_TREES_H

#include <string>
#include <vector>

/*
 * Medium
 */

struct TreeNode;

// 94. Binary Tree Inorder Traversal
std::vector<int> inorderTraversal(TreeNode* root);

// 200. Number of Islands
int numIslands(std::vector<std::vector<char>>& grid);

// 331. Verify Preorder Serialization of a Binary Tree
bool isValidSerialization(const std::string& preorder);
bool isValidSerialization2(const std::string& preorder);


#endif //CLION_TREES_H