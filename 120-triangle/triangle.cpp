class Solution {
public:

   int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    int n = triangle.size();
       if(i == n-1){
       return triangle[i][j];
       }
       if(dp[i][j] != -1) return dp[i][j];
        
       int down = triangle[i][j] + f(i+1,j,triangle,dp);
       int dg = triangle[i][j] + f(i+1,j+1,triangle,dp);
       return dp[i][j] = min(down,dg);
   }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        dp[0][0] = triangle[0][0];

        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
             int up = INT_MAX, leftUp = INT_MAX;

            if(j < i) up = dp[i-1][j];
            if(j > 0) leftUp = dp[i-1][j-1];

            dp[i][j] = triangle[i][j] + min(up, leftUp);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].begin() + n);
    }
};