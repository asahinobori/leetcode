/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int travel(struct TreeNode* root, int depth, int *pMinDepth) {
    if (root == NULL) return 0;
    depth++;
    if (root->left == NULL && root->right == NULL) {
        if (depth < *pMinDepth) {
            *pMinDepth = depth;
        }
    }
    travel(root->left, depth, pMinDepth);
    travel(root->right, depth, pMinDepth);
    return *pMinDepth;
}

int minDepth(struct TreeNode* root) {
    int minDepth = INT_MAX;
    return travel(root, 0, &minDepth);
}

