/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track){

     queue<TreeNode*> q;
     q.push(root);

     while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent_track[node->right] = node;
            q.push(node->right);
        }
     }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;

        mark_parent(root,parent_track);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level = 0;
 
        while(!q.empty()){
          int size = q.size();
          if(level++ == k) break;

          for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left && !visited[node->left]){
            q.push(node->left);
            visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent_track[node] && !visited[parent_track[node]]){
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
          }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};