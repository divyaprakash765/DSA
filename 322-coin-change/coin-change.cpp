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
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            } else{
                dp[0][i] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int t = 0;t <= amount;t++){
                int pick = 1e9;
                if(coins[i] <= t){
                    pick = 1 + dp[i][t-coins[i]];
                }
                int notPick = dp[i-1][t];
                dp[i][t] = min(pick,notPick);
            }
        }
          int ans = dp[n - 1][amount];
    
    
    if (ans >= 1e9)
        return -1;
    
    return ans;
    }
};