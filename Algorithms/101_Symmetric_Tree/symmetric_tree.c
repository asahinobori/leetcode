/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool depthSymTravel(struct TreeNode* left, struct TreeNode* right){
    bool ret;
    if(left != NULL && right != NULL){
        if(left->val != right->val)
            return false;
    }else if(left == NULL && right == NULL){
        return true;
    }else{
        return false;
    }
    return (depthSymTravel(left->left, right->right) && depthSymTravel(left->right, right->left));
}

bool isSymmetric(struct TreeNode* root) {
    return depthSymTravel(root, root);
}

