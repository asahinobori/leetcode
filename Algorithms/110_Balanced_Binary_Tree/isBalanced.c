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
    return (depLeft > depRight ? depLeft : depRight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    int diff = depth(root->left) - depth(root->right);
    if (diff > 1 || diff < -1) {
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
    }
}