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
void displayTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(TreeNode* root){
    if(root==NULL){
         return 0;
    }
    int ans=root->val+sum(root->left)+sum(root->right);
    return ans;
}
int size_of_tree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int size=1+size_of_tree(root->left)+size_of_tree(root->right);
    return size;
}
int max_node(TreeNode* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->val,max(max_node(root->left),max_node(root->right)));
}
int product(TreeNode* root){
    if(root==NULL){
        return 1;
    }
    return root->val*product(root->left)*product(root->right);
}
int min_val(TreeNode* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->val,min(min_val(root->left),min_val(root->right)));
}
int level_of_tree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(level_of_tree(root->left),level_of_tree(root->right));
}
int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);
    //TreeNode* h=new Node(8);
    //TreeNode* i=new Node(9);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size_of_tree(a)<<endl;
    cout<<max_node(a)<<endl;
    cout<<product(a)<<endl;
    cout<<min_val(a)<<endl;
    cout<<level_of_tree(a)<<endl;
    return 0;
}