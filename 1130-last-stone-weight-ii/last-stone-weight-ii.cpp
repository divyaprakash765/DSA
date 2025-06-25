class Solution {
public:
    int OFFSET = 3000; // To handle negative sums
    int f(int i, int sum, vector<int>& stones, vector<vector<int>>& dp) {
        if (i >= stones.size()) {
            if (sum < 0) return 1e8;
            return sum;
        }

        if (dp[i][sum + OFFSET] != -1) return dp[i][sum + OFFSET];

        int add = f(i + 1, sum + stones[i], stones, dp);
        int sub = f(i + 1, sum - stones[i], stones, dp);

        return dp[i][sum + OFFSET] = min(add, sub);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * OFFSET + 1, -1));
        return f(0, 0, stones, dp);
    }
};
