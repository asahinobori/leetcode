/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool depthSymTravel(struct TreeNode* p, struct TreeNode* q){
    bool ret;
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    return p->val == q->val
            && depthSymTravel(p->left, q->right)
            && depthSymTravel(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return depthSymTravel(root, root);
}

