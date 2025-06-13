/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lastRightChild(TreeNode* root) {
        while (root->right) root = root->right;
        return root;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == nullptr){
            return root->right;
        } if(root->right == nullptr){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = lastRightChild(root->left);
        lastRight->right = rightChild; 
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
       
        if(root->val == key) return helper(root); 

        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr->val > key){
                if(curr->left != nullptr && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break; 
                } else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right != nullptr && curr->right->val == key){
                    curr->right = helper(curr->right);
                    break; 
                } else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};