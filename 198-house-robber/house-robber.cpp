class Solution {
public:

    int f(int i,vector<int>& nums,vector<int>& dp){
        if(i >= nums.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(i+2,nums,dp);
        int notPick = f(i+1,nums,dp);

        return dp[i] = max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
          if (n == 0) return 0;
    if (n == 1) return nums[0];


        vector<int> dp(n+1,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

         for(int i=2;i<n;i++){
            int pick = dp[i-1];
            int notPick = nums[i] + dp[i-2];
            dp[i] = max(pick,notPick);
         }

        return dp[n-1];
    }
};