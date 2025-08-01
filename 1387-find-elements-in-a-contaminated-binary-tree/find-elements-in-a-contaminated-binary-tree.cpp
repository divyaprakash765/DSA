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
class FindElements {
public:
    set<int> s;
    void recover_tree(TreeNode* root,int x){
        if(root == nullptr) return;
        s.insert(x);
       root->val = x;
       if(root->left){
        recover_tree(root->left,2*x+1);
       }
       if(root->right){
        recover_tree(root->right,2*x+2);
       }
    }
    FindElements(TreeNode* root) {
        recover_tree(root,0);
    }
    
    bool find(int target) {
        if(s.find(target) != s.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */