class Solution {
    public:
        TreeNode* BuildHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &postorder, int postStart, int postEnd) {
            if (preStart > preEnd || postStart > postEnd) return nullptr;
            TreeNode* root = new TreeNode(preorder[preStart]);
            if (preStart == preEnd) return root;  
            int postIndex = -1;
            for (int i = postStart; i <= postEnd; i++) {
                if (postorder[i] == preorder[preStart + 1]) {
                    postIndex = i;
                    break;
                }
            }
            int leftSubtreeSize = postIndex - postStart + 1;
            root->left = BuildHelper(preorder, preStart + 1, preStart + leftSubtreeSize, postorder, postStart, postIndex);
            root->right = BuildHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, postorder, postIndex + 1, postEnd - 1);
            return root;
        }
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            return BuildHelper(preorder, 0, n - 1, postorder, 0, n - 1);
        }
    };