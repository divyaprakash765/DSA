class Solution {
public:

    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){

        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
       int down = INT_MAX;
      int right = INT_MAX;
     if(i+1<n) down = grid[i][j] + f(i+1,j,grid,dp);
     if(j+1<m) right = grid[i][j] + f(i,j+1,grid,dp);
        return dp[i][j] = min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0] = grid[0][0];

        for(int i=1;i<n;i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int i=1;i<m;i++){
        dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
            int up = grid[i][j] + dp[i-1][j];
            int down = grid[i][j] + dp[i][j-1];
            dp[i][j] = min(up,down);
            }
        }
        return dp[n-1][m-1];
    }
};