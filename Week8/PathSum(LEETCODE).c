bool preorderTraversal(struct TreeNode* root, int currentSum, int targetSum) {
    
    if (root == NULL) {
        return false;
    }

    currentSum += root->val;

    if (root->left == NULL && root->right == NULL) {
        return currentSum == targetSum;
    }

    return preorderTraversal(root->left, currentSum, targetSum) ||
           preorderTraversal(root->right, currentSum, targetSum);
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    return preorderTraversal(root, 0, targetSum);
}
