class Solution {
public:
    int level_of_tree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(level_of_tree(root->left),level_of_tree(root->right));
}
void nthlevel(TreeNode* root,int curr,int level,vector<int>&v){
    if(root==NULL) return;
    if(curr==level) {v.push_back(root->val);
                    }
    if(level%2!=0){
    nthlevel(root->left,curr+1,level,v);
    nthlevel(root->right,curr+1,level,v);
    }
    else {
    nthlevel(root->right,curr+1,level,v);
    nthlevel(root->left,curr+1,level,v);
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     int n=level_of_tree(root);
        vector<vector<int>>a;
        vector<int>v;
     for(int i=1;i<= n;i++){
         nthlevel(root,1,i,v);
         a.push_back(v);
         while(v.size()>0){
             v.pop_back();
         }
     }
        return a;
    }
}; 

// second approach

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root, int flag) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);  // To store nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                // Insert at correct position based on flag
                if (flag)
                    level[i] = temp->val;  // Left to right order
                else
                    level[size - 1 - i] = temp->val;  // Right to left order (reversing)
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }   
            ans.push_back(level);
            flag = !flag;  // Toggle flag for next level
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root, 1);
    }
};

