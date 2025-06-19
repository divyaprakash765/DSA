class Solution {
public:
    

    int f(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i == n-1 && j == m-1) return 1;

        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int down = f(i+1,j,m,n,dp);
        int right = f(i,j+1,m,n,dp);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) continue;
                int up = 0;
                int left = 0;
                if(i-1 >= 0) up = dp[i-1][j];
                if(j-1 >= 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[n-1][m-1];
    }
};