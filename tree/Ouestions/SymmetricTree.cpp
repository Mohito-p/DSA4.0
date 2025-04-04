class Solution {
public:
bool helper(TreeNode* left,TreeNode* right){
    if(left==NULL || right==NULL){
        return left==right;
    }
    if(left->val!=right->val) return false;
    return helper(left->left,right->right) && helper(left->right,right->left);
}
    bool isSymmetric(TreeNode* root) {
        return root==NULL || helper(root->left,root->right);
    }
};