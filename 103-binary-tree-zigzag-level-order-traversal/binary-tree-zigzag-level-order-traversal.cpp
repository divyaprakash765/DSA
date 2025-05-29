/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool temp = false;
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> levels;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                levels.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                } if(node->right){
                    q.push(node->right);
                }
            }
            temp = !temp;
            if(!temp){
                reverse(levels.begin(),levels.end());
            }
            ans.push_back(levels);
        }
        return ans;
    }
};