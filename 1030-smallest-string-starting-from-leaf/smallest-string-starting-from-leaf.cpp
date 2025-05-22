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
    string ans = "~";

    void helper(TreeNode* root,string s){
    if(root == nullptr) return;
    s += (char)(root->val + 'a');
    if(root->left == nullptr && root->right == nullptr){
        reverse(s.begin(),s.end());
        if(s < ans) ans = s;
        
        return;
    }

    helper(root->left,s);
    helper(root->right,s);

    }

    string smallestFromLeaf(TreeNode* root) {
        
        string s = "";

        helper(root,s);

        return ans;
    }
};