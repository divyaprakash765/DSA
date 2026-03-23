class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long mod = 1e9 + 7;

        // dp[i][j] = {maxProd, minProd} reaching (i,j)
        vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long,long long>>(m));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int i = 1; i < n; i++)
            dp[i][0] = {dp[i-1][0].first * grid[i][0], dp[i-1][0].second * grid[i][0]};
        for (int j = 1; j < m; j++)
            dp[0][j] = {dp[0][j-1].first * grid[0][j], dp[0][j-1].second * grid[0][j]};

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long g = grid[i][j];
                long long a = dp[i-1][j].first * g,  b = dp[i-1][j].second * g;
                long long c = dp[i][j-1].first * g,  d = dp[i][j-1].second * g;
                dp[i][j] = {max({a,b,c,d}), min({a,b,c,d})};
            }
        }

        long long ans = dp[n-1][m-1].first;
        return ans < 0 ? -1 : ans % mod;
    }
};