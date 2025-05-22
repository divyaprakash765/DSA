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
    vector<string> ans;
    bool isLeaf(TreeNode* root){
        return (root->left == nullptr) && (root->right == nullptr);
    }
    void helper(TreeNode* root,string s){
        if(root == nullptr) return;
        if(isLeaf(root)){
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        s += to_string(root->val) + "->";
        helper(root->left,s);
        helper(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        helper(root,s);
        return ans;
    }
};