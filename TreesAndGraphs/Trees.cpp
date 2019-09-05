#include "Trees.h"

#include <stack>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
 * 94. Binary Tree Inorder Traversal
 * Medium
 *
 * Iterative solution
 * speed: 0ms, faster than 100%
 * memory: 8.9MB, less than 97.24%
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 */
std::vector<int> inorderTraversal(TreeNode* root) {

    std::vector<int> result;
    std::stack<TreeNode*> stack;

    if (root) stack.push(root);
    else return result;

    while (!stack.empty()) {

        TreeNode* top = stack.top();

        if (top->left) {
            stack.push(top->left);
            top->left = nullptr;
            continue;
        }

        result.push_back(top->val);
        stack.pop();

        if (top->right) {
            stack.push(top->right);
            top->right = nullptr;
        }
    }

    return result;
}