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
    vector<vector<int>> ans;
    void f(TreeNode* root,int targetSum,int sum,vector<int>& root_to_leaf){
        if(root->left == NULL && root->right == NULL){
            sum += root->val;
            if(sum == targetSum){
                root_to_leaf.push_back(root->val);
                ans.push_back(root_to_leaf);
                root_to_leaf.pop_back();
            }
            return;
        }
        root_to_leaf.push_back(root->val);
        if(root->left) f(root->left,targetSum,sum + root->val,root_to_leaf);
        if(root->right) f(root->right,targetSum,sum + root->val,root_to_leaf);
        root_to_leaf.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        vector<int> root_to_leaf;
        f(root,targetSum,0,root_to_leaf);
        return ans;
    }
};