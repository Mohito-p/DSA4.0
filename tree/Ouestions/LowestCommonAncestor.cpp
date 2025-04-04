class Solution {
public:
    bool exist(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exist(root->left,target) || exist(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(exist(root->left,p)&& exist(root->right,q)) return root;
        else if(exist(root->left,q)&& exist(root->right,p)) return root;
        else if(exist(root->left,p)&& !exist(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};

//another way

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q || root == p || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        if (left == NULL) return right;
        return left;
    }