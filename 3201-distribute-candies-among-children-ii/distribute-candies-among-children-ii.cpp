class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int people = 3;
        vector<vector<long long>> dp(people + 1, vector<long long>(n + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= people; i++) {
            vector<long long> prefix(n + 1, 0);
            prefix[0] = dp[i - 1][0];
            for (int j = 1; j <= n; j++) {
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]);
            }

            for (int j = 0; j <= n; j++) {
                if (j - limit - 1 >= 0)
                    dp[i][j] = prefix[j] - prefix[j - limit - 1];
                else
                    dp[i][j] = prefix[j];
            }
        }

        return dp[people][n];
    }
};
