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
void min_maxHorLevel(TreeNode* root,int& minlevel,int& maxlevel,int level){
     if(root==NULL) return ;
     minlevel=min(minlevel,level);
     maxlevel=max(maxlevel,level);
     min_maxHorLevel(root->left,minlevel,maxlevel,level-1);
     min_maxHorLevel(root->right,minlevel,maxlevel,level+1);
}
void top_view(vector<int>& topview,TreeNode* root,int level){
    if(root==NULL) return;
    if(topview[level]==INT_MIN) topview[level]=root->val;
    top_view(topview,root->left,level-1);
    top_view(topview,root->right,level+1);
}
void bottom_view(vector<int>& bottomview,TreeNode* root,int level){
    if(root==NULL) return;
    bottomview[level]=root->val;
    bottom_view(bottomview,root->left,level-1);
    bottom_view(bottomview,root->right,level+1);
}
int main(){
    int n;
    cin>>n;
    vector<int>a;
    int v[n]={1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,8};
    TreeNode* root=construct(v,n);
    levelOrderusingQueue(root);
    cout<<endl;
    int minlevel=0;
    int maxlevel=0;
    min_maxHorLevel(root,minlevel,maxlevel,0);
    int horlevel=maxlevel-minlevel+1;
    vector<int>topview(horlevel,INT_MIN);
    vector<int>bottomview(horlevel,INT_MIN);
    top_view(topview,root,-minlevel);
    bottom_view(bottomview,root,-minlevel);
    for(int i=0;i<
    horlevel;i++){
        cout<<topview[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<
    horlevel;i++){
        cout<<bottomview[i]<<" ";
    }
    return 0;
}