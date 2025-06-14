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
    int size_LST(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + size_LST(root->left) + size_LST(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        int size_lst = size_LST(root->left);
        if(size_lst == k-1) return root->val;
        else if(size_lst >= k){
         return kthSmallest(root->left,k);
        } else{
            return kthSmallest(root->right,k-size_lst-1);
        }
    }
};