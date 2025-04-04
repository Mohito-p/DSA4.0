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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
               unordered_map<TreeNode*, TreeNode*>parent_track;
       markParents(root,parent_track);
       unordered_map<TreeNode* ,bool> visited;
       queue<TreeNode*>qq;
       qq.push(target);
       visited[target]=true;
       int level=0;
       while(!qq.empty()){
        int size=qq.size();
        if(level++==k) break;
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
       vector<int> result;
       while(!qq.empty()){
        TreeNode* current=qq.front();
        qq.pop();
        result.push_back(current->val);
       }
       return result;
    }
};