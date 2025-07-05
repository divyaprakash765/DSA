class Solution {
public:

    int min_val(int num,TreeNode* root){
        if(!root) return -1e9;
        int ans = max(abs(num-root->val),max(min_val(num,root->left),min_val(num,root->right)));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = -1;
        ans = max(ans,max(min_val(root->val,root->left),min_val(root->val,root->right)));
        ans = max(ans,maxAncestorDiff(root->left));
        ans = max(ans,maxAncestorDiff(root->right));

        return ans;
    }
};