class Solution {
public:
    int f(int i, int currSum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (i == nums.size()) {
            return (currSum == target) ? 1 : 0;
        }

        if (dp[i][currSum + offset] != -1) return dp[i][currSum + offset];

        int add = f(i + 1, currSum + nums[i], nums, target, dp, offset);
        int sub = f(i + 1, currSum - nums[i], nums, target, dp, offset);

        return dp[i][currSum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return f(0, 0, nums, target, dp, offset);
    }
};
