class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
     int n = matrix.size();
     int m = matrix[0].size();
     if(i == n-1){
        return matrix[i][j];
     }
     if(dp[i][j] != -1) return dp[i][j];
     int down = matrix[i][j] + f(i+1,j,matrix,dp);
     int dg_left = INT_MAX;
     if(j-1 >= 0) dg_left = matrix[i][j] + f(i+1,j-1,matrix,dp);
     int dg_right = INT_MAX;
     if(j+1 < m) dg_right = matrix[i][j] + f(i+1,j+1,matrix,dp);

     return dp[i][j] = min(down,min(dg_left,dg_right));

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int down = matrix[i][j] + dp[i-1][j];
                int dg_left = INT_MAX;
                int dg_right = INT_MAX;
                if(j-1 >= 0) dg_left = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < n) dg_right = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(down,min(dg_left,dg_right));
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};