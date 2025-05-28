class Solution {
public:
    // DFS helper that returns how many nodes are reachable within `k` steps
    void dfs(int node, int parent, int depth, int k, unordered_map<int, vector<int>>& adj, int& count) {
        if (depth > k) return;
        count++; // count the current node
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, k, adj, count);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        
        unordered_map<int, vector<int>> adj1, adj2;

        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // Precompute max reachable nodes in tree2 within k-1 distance
        int max_reach_tree2 = 0;
        for (int i = 0; i < n2; ++i) {
            int count = 0;
            dfs(i, -1, 0, k - 1, adj2, count);
            max_reach_tree2 = max(max_reach_tree2, count);
        }

        vector<int> result(n1);
        for (int i = 0; i < n1; ++i) {
            int count = 0;
            dfs(i, -1, 0, k, adj1, count);
            result[i] = count + max_reach_tree2;
        }

        return result;
    }
};
