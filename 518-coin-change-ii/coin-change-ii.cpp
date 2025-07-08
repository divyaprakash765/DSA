// [1 2 5]

// 5 - 1
// 2- 2, 1-2
// 1 - 5
// 1-3 , 1-2

class Solution {
public:

   int f(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
     
     int n = coins.size();

     if(amount == 0) return 1;
     if(i >= n) return 0;
     if(dp[i][amount] != -1) return dp[i][amount];

     int pick = 0;
     if(coins[i] <= amount){
        pick = f(i,amount-coins[i],coins,dp);
     }
     int notPick = f(i+1,amount,coins,dp);

    return dp[i][amount] = pick + notPick;
   }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
  
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return f(0,amount,coins,dp);
    }
};