//For the path we will take this path as with thw heights 

class Solution {
public:
int maxi=0;
    int Height(TreeNode* root) {
         if(root==NULL){
        return 0;
    }
    return 1+max(Height(root->left),Height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
      if(root==NULL) return 0;
      int lh=Height(root->left);
      int rh=Height(root->right);
      maxi=max(maxi,lh+rh);
      diameterOfBinaryTree(root->left);
      diameterOfBinaryTree(root->right);
      return maxi;
    }
};

//for O(n)
