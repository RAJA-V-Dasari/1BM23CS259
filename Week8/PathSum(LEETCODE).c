#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkPathSum(struct TreeNode* root, int currentSum, int targetSum) {

    if (root == NULL) {
        return false;
    }
    currentSum += root->val;
    if (root->left == NULL && root->right == NULL) {
        return currentSum == targetSum;
    }

    return checkPathSum(root->left, currentSum, targetSum) ||
           checkPathSum(root->right, currentSum, targetSum);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return checkPathSum(root, 0, targetSum);
}
