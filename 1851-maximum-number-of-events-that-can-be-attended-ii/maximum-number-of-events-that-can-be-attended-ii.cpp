class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i, int k, vector<vector<int>>& events, vector<int>& starts) {
        if (i == events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int next = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();

        int take = events[i][2] + dfs(next, k - 1, events, starts);
        int skip = dfs(i + 1, k, events, starts);

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<int> starts;
        for (auto &e : events) starts.push_back(e[0]);

        int n = events.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return dfs(0, k, events, starts);
    }
};
