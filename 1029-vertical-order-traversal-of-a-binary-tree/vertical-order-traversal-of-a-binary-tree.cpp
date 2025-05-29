class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        // queue of (node, (vertical, level))
        queue<pair<TreeNode*, pair<int, int>>> q;
        // map: vertical -> level -> multiset of node values
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int vert = it.second.first;
            int level = it.second.second;

            mp[vert][level].insert(node->val);

            if (node->left)
                q.push({node->left, {vert - 1, level + 1}});
            if (node->right)
                q.push({node->right, {vert + 1, level + 1}});
        }

        for (auto& p : mp) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
