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
void preorder(TreeNode* root){
  if(root==NULL){
    return ;
  }
    stack<TreeNode*>st;
    st.push(root);
    while(st.size()>0){
      TreeNode* temp=st.top();
      st.pop();
      cout<<temp->val<<" ";
      if(temp->right!=NULL) st.push(temp->right);
      if(temp->left!=NULL) st.push(temp->left);
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
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    preorder(a);
    return 0;
}