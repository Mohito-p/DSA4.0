// #BFS

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
TreeNode* construct(int a[],int n){
    queue<TreeNode*>q;
    TreeNode* root=new TreeNode(a[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        TreeNode* temp=q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        if(a[i]!=INT_MIN) l=new TreeNode(a[i]);
        else l=NULL;
        if(j!=n && a[j]!=INT_MIN) r=new TreeNode(a[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}
void levelOrderusingQueue(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()>0){
        TreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
void leftBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL)leftBoundary(root->right);    
}
void bottomBoundary(TreeNode* root){
    if(root==NULL)   return;
    if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
void rightBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    rightBoundary(root->right);
    if(root->right==NULL)rightBoundary(root->left);
    cout<<root->val<<" ";
}
void boundary(TreeNode* root){
    leftBoundary(root);
    bottomBoundary(root);
    rightBoundary(root->right);
}
int main(){
    int n;
    cin>>n;
    int v[n]={1,2,3,4,5,6,7};
    TreeNode* root=construct(v,n);
    boundary(root);
    return 0;
}