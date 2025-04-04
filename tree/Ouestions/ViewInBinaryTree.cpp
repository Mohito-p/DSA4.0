//Top View 
vector<int> topView(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
       auto it=q.front();
       q.pop();
       Node* node=it.first;
       int line=it.second;
       if(mp.find(line)==mp.end()) mp[line]=node->data;

       if(node->left!=NULL){
         q.push({node->left,line-1});
       }
       if(node->right!=NULL){
        q.push({node->right,line+1});
       }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

//Bottom View

#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    vector<int> ans;
    if (root == NULL) return ans;
    queue<pair<TreeNode<int>*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;
        mp[line] = node->data;
        if (node->left != NULL) {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL) {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}

//Right View
class Solution {
public:
    void recursion(TreeNode* root,int level,vector<int> &res){
        if(root==NULL) return;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
    }
};
//left view
#include<bits/stdc++.h>
void recursion(TreeNode* root,int level,vector<int> &res){
        if(root==NULL) return;
        if(res.size()==level) res.push_back(root->data);
        recursion(root->left,level+1,res);
        recursion(root->right,level+1,res);   
    }
vector<int> printLeftView(BinaryTreeNode<int>* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
}