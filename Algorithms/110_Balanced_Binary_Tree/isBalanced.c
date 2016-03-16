/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int depLeft = depth(root->left);
    int depRight = depth(root->right);
    int diff = depLeft - depRight;
    // 剪枝
    if (depLeft < 0 || depRight < 0 || diff < -1 || diff > 1) return -1;
    return (depLeft > depRight ? depLeft : depRight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return depth(root) >= 0;
}