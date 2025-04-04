class Solution {
public:
void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
    queue<TreeNode*>queue;
    queue.push(root);
    while(!queue.empty()){
        TreeNode* current=queue.front();
        queue.pop();
        if(current->left){
            parent_track[current->left]=current;
            queue.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            queue.push(current->right);
        }
    }
}
TreeNode* find(TreeNode* root, int start) {
    if (root == nullptr) return nullptr;
    if (root->val == start) return root;
    TreeNode* leftResult = find(root->left, start);
    if (leftResult) return leftResult;
    return find(root->right, start);
}

    int amountOfTime(TreeNode* root, int start) {
       unordered_map<TreeNode*, TreeNode*>parent_track;
       markParents(root,parent_track);
       unordered_map<TreeNode* ,bool> visited;
       queue<TreeNode*>qq;
       TreeNode* node=find(root,start);
       qq.push(node);
       visited[node]=true;
       int level=0;
       while(!qq.empty()){
        int size=qq.size();
        level++;
        for(int i=0;i<size;i++){
            TreeNode* current=qq.front();
            qq.pop();
            if(current->left && !visited[current->left]){
                qq.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                qq.push(current->right);
                visited[current->right]=true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                qq.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
       }
       return level-1;
    }
};