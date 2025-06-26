class Solution {
public:
    int f(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        int n = coins.size();
        if(i == n-1){
            if(amount % coins[i] == 0) return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int pick = INT_MAX;
        if(coins[i] <= amount) pick = 1 + f(i,coins,amount-coins[i],dp);
        int notPick = f(i+1,coins,amount,dp);
        return dp[i][amount] = min(pick,notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return f(0,coins,amount,dp) == 1e9 ? -1 : f(0,coins,amount,dp);
    }
};