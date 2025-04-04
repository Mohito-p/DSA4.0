class Solution {
    public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = -1;
        int i=inStart;
        while(i<=inEnd){
          if(inorder[i] == root->val){
            inIndex = i;
            break;
          }
          i++;
        }
        int leftPush=inIndex - inStart;
        //int rightPush=inEnd - inIndex;
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftPush , inorder, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + leftPush+ 1, preEnd, inorder, inIndex + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1);
    }
    };