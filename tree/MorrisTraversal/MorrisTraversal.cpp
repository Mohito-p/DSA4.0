class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>inorder;
            TreeNode* curr=root;
            while(curr!=NULL){
                if(curr->left==NULL){
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
                else{
                    TreeNode* pred=curr->left;
                    while(pred->right!=NULL && pred->right!=curr){
                        pred=pred->right;
                    }
                    if(pred->right==NULL){
                        pred->right=curr;
                        curr=curr->left;
                    }
                    else{
                        pred->right=NULL;
                        inorder.push_back(curr->val);
                        curr=curr->right;
                    }
                }
            }
            return inorder;
        }
    };