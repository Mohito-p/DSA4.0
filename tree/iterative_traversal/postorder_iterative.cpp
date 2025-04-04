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
void postorder(TreeNode* root){
  if(root==NULL){
    return;
  }
    stack<TreeNode*>st;
    vector<int>v;
    st.push(root);
    while(st.size()>0){
      TreeNode* temp=st.top();
      st.pop();
      v.push_back(temp->val);
      if(temp->left!=NULL) st.push(temp->left);
      if(temp->right!=NULL) st.push(temp->right);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
    }
}

//using single stack function
void postorder2(TreeNode* root){
  if(root==NULL) return ;
  stack<TreeNode*>st;
  TreeNode* curr=root;
  while(curr!=NULL || !st.empty()){
    if(curr!=NULL){
      st.push(curr);
      curr=curr->left;
    }
    else{
      TreeNode* temp=st.top()->right;
      if(temp==NULL){
        temp=st.top();
        st.pop();
        cout<<temp->val<<" ";
        while(!st.empty() && temp==st.top()->right){
          temp=st.top();
          st.pop();
          cout<<temp->val<<" ";
        }
      }
      else{
        curr=temp;
      }
    }
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
    postorder(a);
    cout<<endl;
    postorder2(a);
    return 0;
}