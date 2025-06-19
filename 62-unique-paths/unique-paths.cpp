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
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,m,n,dp);
    }
};