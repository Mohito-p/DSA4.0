class Solution {
    public:
    void helper(TreeNode* root,int & sum){
        if(!root) return;
        if(root->val%2==0){
            if(root->left){
               if(root->left->left){
                sum+=root->left->left->val;
               }
               if(root->left->right){
                sum+=root->left->right->val;
               }
            }
            if(root->right){
               if(root->right->left){
                sum+=root->right->left->val;
               }
               if(root->right->right){
                sum+=root->right->right->val;
               }
            }
        }
        helper(root->left,sum);
        helper(root->right,sum);
    }
        int sumEvenGrandparent(TreeNode* root) {
            if(!root) return 0;
            int sum=0;
            helper(root,sum);
            return sum;
        }
    };