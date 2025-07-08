class Solution {
public:

    int f(int i1,int i2,string& s1,string& s2,vector<vector<int>>& dp){

         if(i1 >= s1.size() || i2 >= s2.size()) return 0;
         if(dp[i1][i2] != -1) return dp[i1][i2];
         int pick = -1;
         int notPick = -1;
         if(s1[i1] == s2[i2]){
            pick = 1 + f(i1+1,i2+1,s1,s2,dp);
         }
         else{
          notPick = max(f(i1+1,i2,s1,s2,dp),f(i1,i2+1,s1,s2,dp));
         }

         return dp[i1][i2] = max(pick,notPick);

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

     return f(0,0,text1,text2,dp);  
    }
};