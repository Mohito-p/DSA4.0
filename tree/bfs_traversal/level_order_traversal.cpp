#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode (int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
      }
};
int level_of_tree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(level_of_tree(root->left),level_of_tree(root->right));
}
void nthlevel(TreeNode* root,int curr,int level){
    if(root==NULL) return;
    if(curr==level) cout<<root->val<<" ";
    nthlevel(root->left,curr+1,level);
    nthlevel(root->right,curr+1,level);
}
void levelOrder(TreeNode* root){
     int n=level_of_tree(root);
     for(int i=1;i<= n;i++){
        nthlevel(root,1,i);
     }
}
int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);
    TreeNode* h=new TreeNode(8);
    TreeNode* i=new TreeNode(9);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    levelOrder(a);
    return 0;
}