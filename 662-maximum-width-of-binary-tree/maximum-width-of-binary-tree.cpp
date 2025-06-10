class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxi = 0;

        while (!q.empty()) {
            long long size = q.size();
            long long minId = q.front().second; // normalize indices to prevent overflow
            long long first = 0, last = 0;

            for (long long i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long id = q.front().second - minId;
                q.pop();

                if (i == 0) first = id;
                if (i == size - 1) last = id;

                if (node->left) q.push({node->left, 2 * id});
                if (node->right) q.push({node->right, 2 * id + 1});
            }

            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};
