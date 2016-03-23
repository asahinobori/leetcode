/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int travel(struct TreeNode* root, bool hasbrother) {
    if (root == NULL) return hasbrother ? INT_MAX : 0;
    int left = travel(root->left, root->right != NULL);
    int right = travel(root->right, root->left != NULL);
    return (left < right ? left : right) + 1;
}

int minDepth(struct TreeNode* root) {
    return travel(root, false);
}
