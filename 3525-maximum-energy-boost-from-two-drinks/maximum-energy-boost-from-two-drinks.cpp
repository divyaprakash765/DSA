class Solution {
public:
    long long f(int i,bool temp,vector<int>& energyDrinkA, vector<int>& energyDrinkB,vector<vector<long long>>& dp){
      int n = energyDrinkA.size();

      if(i >= n) return 0;
      if(dp[i][temp] != -1) return dp[i][temp];
      long long first = INT_MIN;
      long long second = INT_MIN;
      if(temp){
        first = max(energyDrinkA[i] + f(i+1,temp,energyDrinkA,energyDrinkB,dp),energyDrinkA[i] + f(i+2,!temp,energyDrinkA,energyDrinkB,dp));
      }
      else{
        second = max(energyDrinkB[i] + f(i+1,temp,energyDrinkA,energyDrinkB,dp),energyDrinkB[i] + f(i+2,!temp,energyDrinkA,energyDrinkB,dp));
      }

     return dp[i][temp] = max(first,second);
    }


    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        
     int n = energyDrinkA.size();

     vector<vector<long long>> dp(n,vector<long long>(2,-1));

     long long ans = max(f(0,1,energyDrinkA,energyDrinkB,dp),f(0,0,energyDrinkA,energyDrinkB,dp));

     return ans;

    }
};