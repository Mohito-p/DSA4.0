class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& postorder, int& postEnd, vector<int>& inorder, int inStart, int inEnd) {
            if (inStart > inEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            postEnd--; 
            int inIndex = -1;
            for (int i = inStart; i <= inEnd; i++) {
                if (inorder[i] == root->val) {
                    inIndex = i;
                    break;
                }
            }
            root->right = buildTreeHelper(postorder, postEnd, inorder, inIndex + 1, inEnd);
            root->left = buildTreeHelper(postorder, postEnd, inorder, inStart, inIndex - 1);
    
            return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int postEnd = postorder.size() - 1;
            return buildTreeHelper(postorder, postEnd, inorder, 0, inorder.size() - 1);
    }
};