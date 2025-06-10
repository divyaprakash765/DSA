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
 typedef long long ll;
class Solution {
public:
    void f(TreeNode* root,ll sum,int& cnt){
        if(root == nullptr) return;
        
        if(root->val == sum) cnt++;
        if(root->left) f(root->left,sum-(ll)(root->val),cnt);
        if(root->right) f(root->right,sum-(ll)(root->val),cnt);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int cnt = 0;
        f(root,(ll)(targetSum),cnt);
        cnt += pathSum(root->left,targetSum);
        cnt += pathSum(root->right,targetSum);
        return cnt;
    }
};