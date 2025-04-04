//One Approach
class Solution {
    private:
        TreeNode* prev=NULL;
    public:
        void flatten(TreeNode* root) {
            if(root==NULL) return ;
            flatten(root->right);
            flatten(root->left);
            root->right=prev;
            root->left=NULL;
            prev=root;
        }
    };

//Another Approach

class Solution {
    public:
        void flatten(TreeNode* root) {
            TreeNode* curr=root;
            while(curr!=NULL){
                if(curr->left!=NULL){
                    TreeNode* pred=curr->left;
                    while(pred->right){
                        pred=pred->right;
                    }
                    pred->right=curr->right;
                    curr->right=curr->left;
                    curr->left=NULL;
                }
                curr=curr->right;
            }
        }
    };