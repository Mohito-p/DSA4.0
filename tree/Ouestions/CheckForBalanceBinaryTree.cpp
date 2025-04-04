class Solution {
public:
    int Height(TreeNode* root) {
         if(root==NULL){
        return 0;
    }
    return 1+max(Height(root->left),Height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftheight=Height(root->left);
        int rightheight=Height(root->right);

        if(abs(rightheight-leftheight)>1) return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(left && right) return true;
        return false;
    }
};

//Another approach or better solution O(N)

int check(node){
    if(node==null) return 0;
    lh=check(node->left);
    rh=check(node->right);

    if(lh==-1 && rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;

    return max(lh,rh)+1;
}