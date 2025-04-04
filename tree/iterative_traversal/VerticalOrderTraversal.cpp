
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node = p.first;
            int x=p.second.first; int y=p.second.second;
            nodes[x][y].insert(node->val);
           if(node->left){
            q.push({node->left, {x-1, y+1}});
           }
           if(node->right){
             q.push({node->right, {x+1, y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto r:nodes){
            vector<int>col;
            for(auto p: r.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    int v[n]={1,2,3,4,5,6,7};
    TreeNode* root=construct(v,n);
    boundary(root);
    return 0;
}