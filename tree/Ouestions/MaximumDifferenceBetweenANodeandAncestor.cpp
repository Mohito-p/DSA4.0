class Solution {
    private:
    void differ(TreeNode* root,int maxVal,int minVal,int & diff){
        if(!root){
            return;
        }
        diff=max(diff,max(abs(minVal-root->val),abs(maxVal-root->val)));
        minVal=min(minVal,root->val);
        maxVal=max(maxVal,root->val);
        differ(root->left,maxVal,minVal,diff);
        differ(root->right,maxVal,minVal,diff);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int diff=0;
        int maxVal=root->val;
        int minVal=root->val;
        differ(root,maxVal,minVal,diff);
        return diff;    
    }
};