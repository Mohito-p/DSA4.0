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
void print_nth_level(TreeNode* root,int x){
    if(root==NULL){
        return;
    }
    if(x==1){
        cout<<root->val<<" ";
    }
    print_nth_level(root->left,x-1);
    print_nth_level(root->right,x-1);
}
int level_of_tree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(level_of_tree(root->left),level_of_tree(root->right));
}
int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(7);
    TreeNode* c=new TreeNode(9);
    TreeNode* d=new TreeNode(2);
    TreeNode* e=new TreeNode(6);
    TreeNode* f=new TreeNode(9);
    TreeNode* g=new TreeNode(5);
    TreeNode* h=new TreeNode(11);
    TreeNode* i=new TreeNode(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=NULL;
    c->right=f;
    e->left=g;
    e->right=h;
    f->left=i;
    print_nth_level(a,3);
    return 0;
}