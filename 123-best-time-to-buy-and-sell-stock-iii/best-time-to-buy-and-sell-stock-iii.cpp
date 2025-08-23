class Solution {
public:
    
    int f(int i,bool buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i >= prices.size() || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int profit = INT_MAX;
        if(buy){
          profit = max(prices[i] + f(i+1,!buy,k-1,prices,dp),f(i+1,buy,k,prices,dp));
        } else{
            profit = max(-prices[i] + f(i+1,!buy,k,prices,dp),f(i+1,buy,k,prices,dp));
        }
       return dp[i][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        return f(0,false,2,prices,dp);
    }
};